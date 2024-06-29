#pragma once

#include <sys/time.h>
#include <time.h>

namespace safe_udp 
{
class SlidWinBuffer 
{
public:
    SlidWinBuffer() {}
    ~SlidWinBuffer() {}

    int first_byte_; //该buffer第一个字节索引值
    int data_length_;  //该buffer的数据大小
    int seq_num_;  //该buffer的序列号
    struct timeval time_sent_; //该buffer发送的时间戳，用于计算RTT
};
}  // namespace safe_udp