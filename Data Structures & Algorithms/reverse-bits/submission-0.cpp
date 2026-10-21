class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = n;
        ret = (ret << 16) | (ret >> 16);
        ret = (((ret & 0xFF00FF00) >> 8) | (ret & 0x00FF00FF) << 8);
        ret = (((ret & 0xF0F0F0F0) >> 4) | (ret & 0x0F0F0F0F) << 4);
        ret = (((ret & 0xCCCCCCCC) >> 2) | (ret & 0x33333333) << 2);
        ret = (((ret & 0xAAAAAAAA) >> 1) | (ret & 0x55555555) << 1);
        return ret;
    }
};
