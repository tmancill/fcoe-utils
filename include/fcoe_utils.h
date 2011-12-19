/*
 * Copyright(c) 2010 Intel Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Maintained at www.Open-FCoE.org
 */

#ifndef _FCOE_UTILS_H_
#define _FCOE_UTILS_H_

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <libgen.h>
#include <dirent.h>
#include <errno.h>

#define MAX_STR_LEN 512
#define MAX_PATH_LEN MAX_STR_LEN

#define SYSFS_MOUNT	"/sys"
#define SYSFS_NET	SYSFS_MOUNT "/class/net"
#define SYSFS_FCHOST	SYSFS_MOUNT "/class/fc_host"
#define SYSFS_FCOE	SYSFS_MOUNT "/module/libfcoe/parameters"

#define FCHOSTBUFLEN 64

/*
 * This macro assumes that progname has been set
 */
#define FCOE_LOG_ERR(fmt, args...)					\
	do {								\
		fprintf(stderr, "%s: " fmt, progname, ##args);		\
	} while (0)


enum fcoe_status {
	SUCCESS = 0,  /* Success */
	EFAIL,        /* Command Failed */
	ENOACTION,    /* No action was taken */
	EFCOECONN,    /* FCoE connection already exists */
	ENOFCOECONN,  /* No FCoE connection on interface */
	ENOFCHOST,    /* FC Host found */
	EINTERR,      /* Internal error */
	EINVALARG,    /* Invalid argument */
	EBADNUMARGS,  /* Invalid number of arguments */
	EIGNORE,      /* Ignore this error value */
	ENOSYSFS,     /* sysfs is not present */
	ENOETHDEV,    /* Not a valid Ethernet interface */
	ENOMONCONN,   /* Not connected to fcoemon */
	ECONNTMOUT,   /* Connection to fcoemon timed out */
	EHBAAPIERR,   /* Error using HBAAPI/libhbalinux */
};

enum fcoe_status fcoe_validate_interface(char *ifname);
enum fcoe_status fcoe_validate_fcoe_conn(char *ifname);
enum fcoe_status fcoe_find_fchost(char *ifname, char *fchost, int len);
int fcoe_checkdir(char *dir);
int check_symbolic_name_for_interface(const char *symbolic_name,
				      const char *ifname);
char *get_ifname_from_symbolic_name(const char *symbolic_name);

#endif /* _FCOE_UTILS_H_ */
