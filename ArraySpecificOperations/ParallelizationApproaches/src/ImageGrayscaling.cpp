// #include <iostream>
// #include <chrono>
// #include <opencv2/opencv.hpp>

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>
#include <chrono>

using namespace std;
using namespace cv;
void detectAndDisplay( Mat frame );
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;



int main(int argc, const char** argv)
{

    std::chrono::system_clock::time_point before;
    std::chrono::system_clock::time_point after;

    bool started = false;
    int frame_number = 0;


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
    //-- 1. Load the cascades
    if( !face_cascade.load( face_cascade_name ) )
    {
        cout << "--(!)Error loading face cascade\n";
        return -1;
    };
    if( !eyes_cascade.load( eyes_cascade_name ) )
    {
        cout << "--(!)Error loading eyes cascade\n";
        return -1;
    };
    int camera_device = parser.get<int>("camera");
    VideoCapture capture;
    //-- 2. Read the video stream
    capture.open( camera_device );
    if ( ! capture.isOpened() )
    {
        cout << "--(!)Error opening video capture\n";
        return -1;
    }
    Mat frame;
    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            cout << "--(!) No captured frame -- Break!\n";
            break;
        }
        //-- 3. Apply the classifier to the frame
        if(!started)
        {
            before = std::chrono::high_resolution_clock::now();
            started = true;
        }


        detectAndDisplay( frame );
        if( waitKey(10) == 27 )
        {
            break; // escape
        }

        if(frame_number < 40)
            frame_number++;
        else
        {
            after = std::chrono::high_resolution_clock::now();
            std::cout<< ((double)frame_number / (double)std::chrono::duration_cast<std::chrono::microseconds>(after-before).count()) * 1000000 << std::endl;
            started = false;
            frame_number = 0;
        }



    }
    return 0;
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
    //-- Show what you got
    //imshow( "Capture - Face detection", frame );
}
















void parallel_grayscaling()
{
    cv::Mat image;
    image = cv::imread("../resources/yugi_muto.png", 1);

    cv::Mat grayscale(image.rows, image.cols, CV_8UC1);

    auto before = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < image.rows; i++)
    {
        for(int j = 0; j < image.cols; j++)
        {
            cv::Vec3b temp = image.at<cv::Vec3b>(i,j);
            grayscale.at<uchar>(i,j) = (temp[0] + temp[1] + temp[2]) / 3;
        }   
    }
    auto after = std::chrono::high_resolution_clock::now();


    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(after - before).count() << std::endl;

    
}




/*

int main()
{
    
    parallel_grayscaling();
    
    
    cv::Mat image, grayscale;
    image = cv::imread("../resources/yugi_muto.png", 1);

    auto before = std::chrono::high_resolution_clock::now();
    cv::cvtColor(image, grayscale, cv::COLOR_BGR2GRAY);
    auto after = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(after - before).count() << std::endl;

    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
   
    
    return 0;
    

    int lowThreshold = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernel_size = 7;


    bool started = false;

    int iterations = 0;
    double average = 0.0;
   

    std::chrono::system_clock::time_point before;
    std::chrono::system_clock::time_point after; 
    int frame_number = 0;   

    cv::VideoCapture cap;
    // open the default camera, use something different from 0 otherwise;
    // Check VideoCapture documentation.
    if(!cap.open(0))
        return 0;


    std::cout << "Calculating Average..." << std::flush;    
    for(;;)
    {
        if(!started)
        {
            before = std::chrono::high_resolution_clock::now();
            started = true;
        }
        cv::Mat src, src_gray, alternate_image;
        cv::Mat dst, detected_edges;
        cap >> src;

        
        cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
        cv::blur( src_gray, detected_edges, cv::Size(3,3) );
        cv::Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
        dst = cv::Scalar::all(0);
        src.copyTo( dst, detected_edges);
        
        cv::imshow("this is you, smile! :)", dst);
          

        if( src.empty() ) break; // end of video stream
        
        if( cv::waitKey(10) == 27 ) break; // stop capturing by pressing ESC 

        if(iterations == 30) break;


        if(frame_number < 20)
            frame_number++;
        else
        {
            after = std::chrono::high_resolution_clock::now();
            //std::cout<< ((double)frame_number / (double)std::chrono::duration_cast<std::chrono::microseconds>(after-before).count()) * 1000000 << std::endl;
            average += ((double)frame_number / (double)std::chrono::duration_cast<std::chrono::microseconds>(after-before).count()) * 1000000;
            frame_number = 0;
            started = false;
            iterations++;
        }

    }

    std::cout << average/30 << std::endl;
    // the camera will be closed automatically upon exit
    // cap.close();
    return 0;



}

*/


/*

#include "opencv2/opencv.hpp"
#include <time.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

    // Start default camera
    VideoCapture video(0);

    // With webcam get(CV_CAP_PROP_FPS) does not work.
    // Let's see for ourselves.

    // double fps = video.get(CV_CAP_PROP_FPS);
    // If you do not care about backward compatibility
    // You can use the following instead for OpenCV 3
    double fps = video.get(CAP_PROP_FPS);
    cout << "Frames per second using video.get(CAP_PROP_FPS) : " << fps << endl;

    // Number of frames to capture
    int num_frames = 120;

    // Start and end times
    time_t start, end;

    // Variable for storing video frames
    Mat frame;

    cout << "Capturing " << num_frames << " frames" << endl ;

    // Start time
    time(&start);

    // Grab a few frames
    for(int i = 0; i < num_frames; i++)
    {
        video >> frame;
    }

    // End Time
    time(&end);

    // Time elapsed
    double seconds = difftime (end, start);
    cout << "Time taken : " << seconds << " seconds" << endl;

    // Calculate frames per second
    fps  = num_frames / seconds;
    cout << "Estimated frames per second : " << fps << endl;

    // Release video
    video.release();
    return 0;
}

*/