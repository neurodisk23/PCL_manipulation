#include <pcl/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

//pcl_viewer -multiview 1 <pcd.file>

using Cloud = pcl::PointCloud<pcl::PointXYZI>;
int main()
{
    Cloud::Ptr cloud(new Cloud);
    Cloud::Ptr hindered_cloud(new Cloud);

    if (pcl::io::loadPCDFile("input.pcd", *cloud))
    {
        PCL_ERROR("Failed reading file");
        return EXIT_FAILURE;
    }


    for (const auto& point : *cloud)
        if (point.intensity <= 230 && point.intensity>= 215 && point.x <=20 && point.x >=0 && point.y <= 3 && point.y >= -3 && point.z >= -2.067 )
            hindered_cloud->push_back(point);

    pcl::io::savePCDFileASCII("file.pcd", *hindered_cloud);
    PCL_INFO("Save successful");


    return EXIT_SUCCESS;
}
