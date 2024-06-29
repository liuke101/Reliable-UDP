#pragma once

#include <cstdint>
#include <cstdlib>

namespace safe_udp
{
    constexpr int MAX_PACKET_SIZE = 1472; //应用层数据部分最大长度，内核提供的IP头+UDP头=28字节，共1500字节
    constexpr int MAX_DATA_SIZE = 1460; //数据部分长度
    constexpr int HEADER_LENGTH = 12; //safe-udp头部长度

    /// @brief safe-udp头部
    class DataSegment 
    {
    public:
        DataSegment();

        ~DataSegment() 
        {
            if (final_packet_ != nullptr) 
            {
                free(final_packet_);
            }
        }

        // 序列化：将DataSegment类对象转换为final_packet_字符数组（二进制数据），即可以再网络中传输的数据包
        char *SerializeToCharArray();

        // 反序列化：将字符数组（二进制数据）转换为DataSegment类对象
        void DeserializeToDataSegment(unsigned char *data_segment, int length);

        int seq_number_; //序号
        int ack_number_; //确认好
        bool ack_flag_;  //确认位
        bool fin_flag_;  //终止位
        uint16_t length_; //UDP数据报长度
        
        char *data_ = nullptr; 

    private:
        uint32_t convert_to_uint32(unsigned char *buffer, int start_index);
        bool convert_to_bool(unsigned char *buffer, int index);
        uint16_t convert_to_uint16(unsigned char *buffer, int start_index);
        char *final_packet_ = nullptr;
    };
}  // namespace safe_udp