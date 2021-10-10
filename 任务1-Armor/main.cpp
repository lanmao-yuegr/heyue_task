#include "Armor.h"


int main()
{
    Mat frame;
    namedWindow("frame", WINDOW_AUTOSIZE);
    Detection Armor;

    // 读取视频文件
    String VideoName = "装甲板_1.avi";
    VideoCapture capture(VideoName);
    if (!capture.isOpened())
    {
        printf("无法打开视频文件！");
        return -1;
    }

    //读取每一帧
    while (capture.read(frame))
    {
        Mat fpsImage;
        ImageAndPoint IAP;
        ContoursRequired CR;

        fpsImage = frame;
        //预处理
        fpsImage = Armor.PreCompile(fpsImage, VideoName);
        //获得所需轮廓
        CR = Armor.GetRequiredContours(fpsImage);
        //绘制角点以及中心点
        IAP = Armor.DrawingImage(frame, fpsImage, CR);

        //显示处理后的图像
        fpsImage = IAP.Image;
        imshow("frame", fpsImage);
        waitKey(40);
    }
}