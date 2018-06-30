#include "gen_version.h"
#include "version.h"
#include <fcntl.h>
#include <stdio.h>

const char *version(void)
{
	return VERSION;
}

char *version_and_exit(const void *unused UNUSED)
{
	printf("%s\n", VERSION);
	if (BUILD_FEATURES[0]) {
		printf("Built with features: %s\n", BUILD_FEATURES);
	}
	exit(0);
}

int get_hardware_wallet_fd(void)
{
	int fd = -1;
	char device_paths[][25] = {
		"/dev/cu.usbmodem14311",
		"/dev/cu.usbmodem1442",
		"/dev/ttyACM0",
		"/dev/ttyACM1",
		"/dev/ttyACM2",
		"/dev/ttyACM3",
		"/dev/ttyACM4",
		"/dev/ttyACM5"
	};
	for (size_t i = 0; i < sizeof(device_paths) / sizeof(device_paths[0]); i++) {
		fd = open(device_paths[i], O_RDWR | O_NOCTTY | O_NDELAY);
		if(fd >= 0) {
			break;
		}
	}
	return fd;
}
