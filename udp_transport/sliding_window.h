#pragma once

#include <vector>

#include "buffer.h"

namespace safe_udp 
{
    /// @brief 滑动窗口类
    class SlidingWindow 
    {
    public:
        SlidingWindow();
        ~SlidingWindow();

        //向滑动窗口添加buffer
        int AddToBuffer(const SlidWinBuffer& buffer);

        std::vector<SlidWinBuffer>
            sliding_window_buffers_;  // 滑动窗口中的buffer

        int last_packet_sent_; //最后发送的数据包的指针
        int last_acked_packet_; //最后确认收到的数据包的指针

        int send_base_;  // 成功发送且已经确认的数据包中最小的序列号
        int dup_ack_;  //重复确认的次数，用于快速重传等机制
    };
}  // namespace safe_udp
