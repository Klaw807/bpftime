#define BPF_NO_GLOBAL_DATA
#include <vmlinux.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/nvme_ioctl.h>
#include <cstdlib>


// SEC("uprobe")
// int do_uprobe_override_patch(struct pt_regs *ctx)
// {
// 	bpf_printk("target_func called is overrided.\n");
// 	bpf_override_return(ctx, 0);
// 	return 0;
// }

SEC("uprobe")
void write_to_nvme(struct pt_regs *ctx) {
	// int fd = (int)ctx->args[0];
	// const char *data = (const char *)ctx->args[1];
	// int data_len = (int)ctx->args[2];
	// int lba = 0; // TODO


    // system("echo 3 > /proc/sys/vm/drop_caches");
    // struct nvme_passthru_cmd cmd;
    // memset(&cmd, 0, sizeof(cmd));
    // cmd.opcode = 0x01; // opcode for Write
    // cmd.addr = (unsigned long)data; // address of the data buffer
    // cmd.nsid = 1; // namespace ID
    // cmd.data_len = data_len; // data length to write
    // cmd.cdw10 = lba; // Lower significant Dword of LBA
    // cmd.cdw11 = 0; // Higher significant Dword of LBA; keeping it 0
    // cmd.cdw12 = SECTORS; // Number of blocks (LBAs) to write

    // int err = ioctl(fd, NVME_IOCTL_IO_CMD, &cmd);
    // if (err < 0) {
    //     perror("NVMe write failed");
    // } else {
    //     printf("Write to LBA %d succeeded\n", lba);
    // }

	bpf_printk("target_func called is overrided.\n");
	bpf_override_return(ctx, 0);
	return 0;	
}
// void write_to_nvme(int fd, int lba, const char *data, int data_len) {
//     system("echo 3 > /proc/sys/vm/drop_caches");
//     struct nvme_passthru_cmd cmd;
//     memset(&cmd, 0, sizeof(cmd));
//     cmd.opcode = 0x01; // opcode for Write
//     cmd.addr = (unsigned long)data; // address of the data buffer
//     cmd.nsid = 1; // namespace ID
//     cmd.data_len = data_len; // data length to write
//     cmd.cdw10 = lba; // Lower significant Dword of LBA
//     cmd.cdw11 = 0; // Higher significant Dword of LBA; keeping it 0
//     cmd.cdw12 = SECTORS; // Number of blocks (LBAs) to write

//     int err = ioctl(fd, NVME_IOCTL_IO_CMD, &cmd);
//     if (err < 0) {
//         perror("NVMe write failed");
//     } else {
//         printf("Write to LBA %d succeeded\n", lba);
//     }
// }


// int write(int handle,void *buf,int len);


char LICENSE[] SEC("license") = "GPL";
