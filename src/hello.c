#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>

int main() {
    while (true) {
        // 获取当前时间点
        auto now = std::chrono::system_clock::now();
        // 将时间点转换为时间结构体
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        // 将时间结构体转换为字符串格式
        char time_str[100];
        std::strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", std::localtime(&now_time));
        // 打印时间
        std::cout << time_str << std::endl;

        // 等待1秒
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
