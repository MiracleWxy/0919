#include <stdio.h>
#include <math.h>
#define M_PI 3.1415926
#define EARTH_RADIUS 6371.0 // 地球半径（单位：千米）

// 将角度从度数转换为弧度
double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// 计算两个经纬度坐标之间的距离（单位：千米）
double calculateDistance(double lat1, double lon1, double lat2, double lon2) {
    // 将经纬度从度数转换为弧度
    lat1 = degreesToRadians(lat1);
    lon1 = degreesToRadians(lon1);
    lat2 = degreesToRadians(lat2);
    lon2 = degreesToRadians(lon2);

    // 使用球面余弦定理计算距离
    double dlon = lon2 - lon1;
    double dlat = lat2 - lat1;
    double a = sin(dlat / 2.0) * sin(dlat / 2.0) + cos(lat1) * cos(lat2) * sin(dlon / 2.0) * sin(dlon / 2.0);
    double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

int main() {
    // 两个经纬度坐标（纬度、经度）示例
    double lat1 = 30.5894118; // 纬度1
    double lon1 = 114.2893445; // 经度1
    double lat2 = 30.5739069; // 纬度2
    double lon2 = 114.3157860; // 经度2

    // 计算距离
    double distance = calculateDistance(lat1, lon1, lat2, lon2);

    // 打印结果
    printf("距离：%.2f 千米\n", distance);

    return 0;
}

