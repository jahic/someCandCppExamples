#include <iostream>
#include <vector>
#include <chrono>
#include <opencv2/opencv.hpp>
#include <thread>
#include <omp.h>

using namespace cv;
using namespace std::chrono_literals;


void detectAndDisplay( Mat frame );
void* parallel_pthread(void* iterator);


std::vector<cv::Mat> images;

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

void create_images(int instance_number)
{
    cv::Mat image = cv::imread("../resources/yugi_muto.png", 1);

     for(int i = 0; i < instance_number; i++)
        images.emplace_back(image);
}

int64_t serial_grayscale(int instance_number)
{
    cv::Mat grayscale;

    std::chrono::system_clock::time_point before = std::chrono::system_clock::now();
    for(int i = 0; i < instance_number; i++)
        cv::cvtColor(images[i], grayscale, cv::COLOR_BGR2GRAY);
    std::chrono::system_clock::time_point after = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}

int64_t parallel_grayscale(int instance_number)
{
    cv::Mat grayscale;

    std::chrono::system_clock::time_point before = std::chrono::system_clock::now();

    #pragma omp parallel for num_threads(12)
    for(int i = 0; i < instance_number; i++)
    {
        cv::cvtColor(images[i], grayscale, cv::COLOR_BGR2GRAY);
    }
        
    std::chrono::system_clock::time_point after = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}

void* my_function(void * image_pointer)
{
    cv::Mat * my_images = (cv::Mat*)image_pointer;
    
    for(int i = 0; i < 800; i++)
    {
        cv::Mat gray;

        cv::cvtColor(my_images[i], gray, cv::COLOR_BGR2GRAY);
    }

    return NULL;
}

int64_t parallel_pthread_grayscale(int instance_number, int thread_number)
{
   cv::setNumThreads(0);
    
    cv::Mat * images_p = new cv::Mat[6400];

    for(int i = 0; i < images.size(); i++)
        images_p[i] = images[i];

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, my_function, (void*)images_p);
    }

    for(int i = 0; i < thread_number; i++)
    {
        pthread_join(threads[i], NULL);
    }

  
    auto after = std::chrono::high_resolution_clock::now();
    
    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();;
}

int64_t serial_pthread_grayscale(int instance_number, int thread_number)
{
   
    
    cv::Mat * images_p = new cv::Mat[6400];

    for(int i = 0; i < images.size(); i++)
        images_p[i] = images[i];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 6400; i++)
    {
        cv::Mat gray;

        cv::cvtColor(images_p[i], gray, cv::COLOR_BGR2GRAY);
    }
    
  
    auto after = std::chrono::high_resolution_clock::now();
    
    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();;
}



int64_t serial_face_detection(int instance_number, int argc, char ** argv)
{
    CommandLineParser parser(argc, argv,
                             "{help h||}"
                             "{face_cascade|../src/haarcascade_frontalface_alt.xml|Path to face cascade.}"
                             "{eyes_cascade|../src/haarcascade_eye_tree_eyeglasses.xml|Path to eyes cascade.}"
                             "{camera|0|Camera device number.}");
    parser.about( "\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
                  "You can use Haar or LBP features.\n\n" );
    
    parser.printMessage();
    String face_cascade_name = samples::findFile( parser.get<String>("face_cascade") );
    String eyes_cascade_name = samples::findFile( parser.get<String>("eyes_cascade") );

    face_cascade.load( face_cascade_name );
    eyes_cascade.load( eyes_cascade_name );
    std::chrono::system_clock::time_point before = std::chrono::system_clock::now();
    for(int i = 0; i < instance_number; i++)
    {
         detectAndDisplay(images[i]);
    }
    std::chrono::system_clock::time_point after = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}

int64_t parallel_open_mp_face_detection(int instance_number, int argc, char ** argv)
{
    CommandLineParser parser(argc, argv,
                             "{help h||}"
                             "{face_cascade|../src/haarcascade_frontalface_alt.xml|Path to face cascade.}"
                             "{eyes_cascade|../src/haarcascade_eye_tree_eyeglasses.xml|Path to eyes cascade.}"
                             "{camera|0|Camera device number.}");
    parser.about( "\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
                  "You can use Haar or LBP features.\n\n" );
    
    parser.printMessage();
    String face_cascade_name = samples::findFile( parser.get<String>("face_cascade") );
    String eyes_cascade_name = samples::findFile( parser.get<String>("eyes_cascade") );

    face_cascade.load( face_cascade_name );
    eyes_cascade.load( eyes_cascade_name );
    std::chrono::system_clock::time_point before = std::chrono::system_clock::now();

    #pragma omp parallel for num_threads(4) collapse(3)
    for(int i = 0; i < instance_number; i++)
    {
        Mat frame_gray;
        cvtColor( images[i], frame_gray, COLOR_BGR2GRAY );
        equalizeHist( frame_gray, frame_gray );
        //-- Detect faces
        std::vector<Rect> faces;
        face_cascade.detectMultiScale( frame_gray, faces );
        for ( size_t k = 0; k < faces.size(); k++ )
        {
            Point center( faces[k].x + faces[k].width/2, faces[k].y + faces[k].height/2 );
            ellipse( images[i], center, Size( faces[k].width/2, faces[k].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4 );
            Mat faceROI = frame_gray( faces[k] );
            //-- In each face, detect eyes
            std::vector<Rect> eyes;
            eyes_cascade.detectMultiScale( faceROI, eyes );
            for ( size_t j = 0; j < eyes.size(); j++ )
            {
                Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
                int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
                circle( images[i], eye_center, radius, Scalar( 255, 0, 0 ), 4 );
            }
        }
    }

    std::chrono::system_clock::time_point after = std::chrono::system_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}

int64_t parallel_pthreads_face_detection(int instance_number, int argc, char ** argv)
{
    cv::setNumThreads(0);
    int thread_number = 8;

    CommandLineParser parser(argc, argv,
                             "{help h||}"
                             "{face_cascade|../src/haarcascade_frontalface_alt.xml|Path to face cascade.}"
                             "{eyes_cascade|../src/haarcascade_eye_tree_eyeglasses.xml|Path to eyes cascade.}"
                             "{camera|0|Camera device number.}");
    parser.about( "\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
                  "You can use Haar or LBP features.\n\n" );
    
    parser.printMessage();
    String face_cascade_name = samples::findFile( parser.get<String>("face_cascade") );
    String eyes_cascade_name = samples::findFile( parser.get<String>("eyes_cascade") );

    face_cascade.load( face_cascade_name );
    eyes_cascade.load( eyes_cascade_name );

    pthread_t threads[thread_number];

    int * iterator = new int[thread_number];

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < thread_number; i++)
    {
        iterator[i] = i;
        pthread_create(&threads[i], NULL, parallel_pthread, (void*)&iterator[i]);
    }

    for(int i = 0; i < thread_number; i++)
    {
        std::cout << "I Joined" << std::endl;
        pthread_join(threads[i], NULL);
        
    }
    auto after = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(after - before).count();
}

void* parallel_pthread(void* iterator)
{
    for(int i = 0; i < 30; i++)
    {
        detectAndDisplay(images[i]);
    }

    return NULL;
}


void detectAndDisplay( Mat frame )
{
    Mat frame_gray;
    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );
    //-- Detect faces
    std::vector<Rect> faces;
    face_cascade.detectMultiScale( frame_gray, faces );
    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
        ellipse( frame, center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4 );
        Mat faceROI = frame_gray( faces[i] );
        //-- In each face, detect eyes
        std::vector<Rect> eyes;
        eyes_cascade.detectMultiScale( faceROI, eyes );
        for ( size_t j = 0; j < eyes.size(); j++ )
        {
            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
            circle( frame, eye_center, radius, Scalar( 255, 0, 0 ), 4 );
        }
    }
}


void run_tests(int instance_number, int argc, char ** argv)
{
    std::this_thread::sleep_for(600ms);

    create_images(instance_number);

    //std::cout << serial_pthread_grayscale(instance_number, 0) << std::endl;
    //std::cout << parallel_pthread_grayscale( instance_number, 8) << std::endl;


    //std::cout   << "Serial   Execution: " << serial_grayscale(instance_number)   << "ms\n"
    //            << "Parallel Execution: " << parallel_grayscale(instance_number) << "ms\n";

  //std::cout << "Serial Face/Eye Detection: " << serial_face_detection(instance_number, argc, argv) << "ms\n";

  //std::cout << "Parallel OpenMP Face/Eye Detection: " << parallel_open_mp_face_detection(instance_number, argc, argv) << "ms\n";

    std::cout << "Parallel Pthread Face/Eye Detection: " << parallel_pthreads_face_detection(instance_number, argc, argv) << "ms\n";
   /* CommandLineParser parser(argc, argv,
                             "{help h||}"
                             "{face_cascade|../src/haarcascade_frontalface_alt.xml|Path to face cascade.}"
                             "{eyes_cascade|../src/haarcascade_eye_tree_eyeglasses.xml|Path to eyes cascade.}"
                             "{camera|0|Camera device number.}");
    parser.about( "\nThis program demonstrates using the cv::CascadeClassifier class to detect objects (Face + eyes) in a video stream.\n"
                  "You can use Haar or LBP features.\n\n" );
    
    parser.printMessage();
    String face_cascade_name = samples::findFile( parser.get<String>("face_cascade") );
    String eyes_cascade_name = samples::findFile( parser.get<String>("eyes_cascade") );

    face_cascade.load( face_cascade_name );
    eyes_cascade.load( eyes_cascade_name );

    std::chrono::high_resolution_clock::time_point before;
    std::chrono::high_resolution_clock::time_point after;


    std::cout << cv::getNumThreads() << std::endl;

    before = std::chrono::high_resolution_clock::now();
   
        for(int i = 0; i < instance_number; i++)
        {
            Mat frame_gray;
            cvtColor( images[i], frame_gray, COLOR_BGR2GRAY );
            equalizeHist( frame_gray, frame_gray );
            //-- Detect faces
            std::vector<Rect> faces;
            face_cascade.detectMultiScale( frame_gray, faces );
            for ( size_t i = 0; i < faces.size(); i++ )
            {
                Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
                ellipse( images[i], center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4 );
                Mat faceROI = frame_gray( faces[i] );
                //-- In each face, detect eyes
                std::vector<Rect> eyes;
                eyes_cascade.detectMultiScale( faceROI, eyes );
                for ( size_t j = 0; j < eyes.size(); j++ )
                {
                    Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
                    int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
                    circle( images[i], eye_center, radius, Scalar( 255, 0, 0 ), 4 );
                }
            }
        }
     after = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(after- before).count() << std::endl;
    */
    /*
    before = std::chrono::high_resolution_clock::now();
        
        for(int i = 0; i < instance_number; i++)
        {
            Mat frame_gray;
            cvtColor( images[i], frame_gray, COLOR_BGR2GRAY );
            equalizeHist( frame_gray, frame_gray );
            //-- Detect faces
            std::vector<Rect> faces;
            face_cascade.detectMultiScale( frame_gray, faces );

            #pragma omp parallel for 
            for ( size_t i = 0; i < faces.size(); i++ )
            {
                Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
                ellipse( images[i], center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4 );
                Mat faceROI = frame_gray( faces[i] );
                //-- In each face, detect eyes
                std::vector<Rect> eyes;
                eyes_cascade.detectMultiScale( faceROI, eyes );

                
                for ( size_t j = 0; j < eyes.size(); j++ )
                {
                    Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
                    int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
                    circle( images[i], eye_center, radius, Scalar( 255, 0, 0 ), 4 );
                }
            }
        }
     after = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(after- before).count() << std::endl;
    */



/*
    before = std::chrono::high_resolution_clock::now();
    cv::parallel_for_(cv::Range(0, images.size()), [&](const cv::Range & range) {
        for(int i = range.start; i < range.end; i++)
        {
            Mat frame_gray;
            cvtColor( images[i], frame_gray, COLOR_BGR2GRAY );
            equalizeHist( frame_gray, frame_gray );
            //-- Detect faces
            std::vector<Rect> faces;
            face_cascade.detectMultiScale( frame_gray, faces );
            for ( size_t i = 0; i < faces.size(); i++ )
            {
                Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
                ellipse( images[i], center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4 );
                Mat faceROI = frame_gray( faces[i] );
                //-- In each face, detect eyes
                std::vector<Rect> eyes;
                eyes_cascade.detectMultiScale( faceROI, eyes );
                for ( size_t j = 0; j < eyes.size(); j++ )
                {
                    Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
                    int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
                    circle( images[i], eye_center, radius, Scalar( 255, 0, 0 ), 4 );
                }
            }
        }
    });
     after = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(after- before).count() << std::endl;
*/
/*
    cv::setNumThreads(4);
    before = std::chrono::high_resolution_clock::now();
    cv::parallel_for_(cv::Range(0, images.size()), [&](const cv::Range & range) {
        for(int i = range.start; i < range.end; i++)
        {
            Mat frame_gray;
            cvtColor( images[i], frame_gray, COLOR_BGR2GRAY );
            equalizeHist( frame_gray, frame_gray );
            //-- Detect faces
            std::vector<Rect> faces;
            face_cascade.detectMultiScale( frame_gray, faces );
            for ( size_t i = 0; i < faces.size(); i++ )
            {
                Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
                ellipse( images[i], center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4 );
                Mat faceROI = frame_gray( faces[i] );
                //-- In each face, detect eyes
                std::vector<Rect> eyes;
                eyes_cascade.detectMultiScale( faceROI, eyes );
                for ( size_t j = 0; j < eyes.size(); j++ )
                {
                    Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
                    int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
                    circle( images[i], eye_center, radius, Scalar( 255, 0, 0 ), 4 );
                }
            }
        }
    });
     after = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(after- before).count() << std::endl;

    cv::setNumThreads(8);
    before = std::chrono::high_resolution_clock::now();
    cv::parallel_for_(cv::Range(0, images.size()), [&](const cv::Range & range) {
        for(int i = range.start; i < range.end; i++)
        {
            Mat frame_gray;
            cvtColor( images[i], frame_gray, COLOR_BGR2GRAY );
            equalizeHist( frame_gray, frame_gray );
            //-- Detect faces
            std::vector<Rect> faces;
            face_cascade.detectMultiScale( frame_gray, faces );
            for ( size_t i = 0; i < faces.size(); i++ )
            {
                Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
                ellipse( images[i], center, Size( faces[i].width/2, faces[i].height/2 ), 0, 0, 360, Scalar( 255, 0, 255 ), 4 );
                Mat faceROI = frame_gray( faces[i] );
                //-- In each face, detect eyes
                std::vector<Rect> eyes;
                eyes_cascade.detectMultiScale( faceROI, eyes );
                for ( size_t j = 0; j < eyes.size(); j++ )
                {
                    Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
                    int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
                    circle( images[i], eye_center, radius, Scalar( 255, 0, 0 ), 4 );
                }
            }
        }
    });
    after = std::chrono::high_resolution_clock::now();

    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(after- before).count() << std::endl;
*/

}


int main(int argc, char ** argv)
{
    run_tests(240, argc, argv);
    return 0;
}