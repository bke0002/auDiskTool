//
// Created by Connor Jones on 7/8/15.
//

#ifndef AUDISKTOOL_CONFIG_INFO_H
#define AUDISKTOOL_CONFIG_INFO_H



class config_info {
    private:
        int interval;
        int count;
        int blk_read;
        int blk_reads;
        int kb_reads;
        int blk_write;
        int blk_writes;
        int kb_write;
        bool config_updated;

    public:
    int getInterval() const { return interval; }

    void setInterval(int interval) {
        if(interval != getInterval())  {
            config_info::interval = interval;
            config_updated = true;
            std::cout << "The sampling interval has been changed to " << interval << "seconds.\n";
        } else {
            std::cout << "Interval is already " << interval;
        }
    }

    int getCount() const { return count; }

    void setCount(int count) { config_info::count = count; }

    int getBlk_read() const { return blk_read; }

    void setBlk_read(int blk_read) { config_info::blk_read = blk_read; }

    int getBlk_reads() const { return blk_reads; }

    void setBlk_reads(int blk_reads) { config_info::blk_reads = blk_reads; }

    int getKb_reads() const { return kb_reads; }

    void setKb_reads(int kb_reads) { config_info::kb_reads = kb_reads; }

    int getBlk_write() const { return blk_write; }

    void setBlk_write(int blk_write) { config_info::blk_write = blk_write; }

    int getBlk_writes() const { return blk_writes; }

    void setBlk_writes(int blk_writes) { config_info::blk_writes = blk_writes; }

    int getKb_write() const { return kb_write; }

    void setKb_write(int kb_write) { config_info::kb_write = kb_write; }

    void printConfig(){}

    void save(){}

};

#endif //AUDISKTOOL_CONFIG_INFO_H