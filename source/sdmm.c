/* diskio implementation for sd memory cards
 * 
 * guidance courtesy of:
 *  @elehobica https://github.com/elehobica/pico_fatfs.git
 *  @elm-chan fatfs sample project http://elm-chan.org/fsw/ff/
 */


/* breadn-note:
	Writing "glue" functions involves using the pico sdk functions to
	interface between fatfs and the rp2040 hardware.

	for ACE 3.0 use application, we are using a read/write SD card so
	the following config in ffconf.h is:
	- FF_FS_READONLY == 0
	- FF_MAX_SS == FF_MIN_SS == 512

	which requires the implementation of the following diskio.h functions:
	- disk_status
	- disk_initialize
	- disk_read
	- disk_write
	- get_fattime	(optional for file timestamps...ACE3 has no RTC so return 0)
	- disk_ioctl

    multiple other static functions are also implemented:
    - 

*/

#include "ff.h"			/* Obtains integer types */
#include "diskio.h"		/* Declarations of disk functions */

#include "pico/stdlib.h"        /* pico sdk stdlib */
#include "sdmm.h"

/* Definitions of physical drive number for each drive 
    NOTE: ACE3.0 only supports MMC */
#define DEV_RAM		0	/* Example: Map Ramdisk to physical drive 0 */
#define DEV_MMC		1	/* Example: Map MMC/SD card to physical drive 1 */
#define DEV_USB		2	/* Example: Map USB MSD to physical drive 2 */


/******************************************************************************/
/*!         Static Variables                                                  */

/* static flag for disk status */
static volatile DSTATUS dstat = STA_NOINIT;

/******************************************************************************/
/*!         Static Function Declaration                                       */



/******************************************************************************/
/*!         Functions                                                         */

/*!
 *  @brief Initialize disk
 *
 *  @param[in] pdrv : Physical drive number indicating type of drive, 1 == MMC
 * 
 *  @return Status of disk as a DSTATUS code
 * */
DSTATUS disk_initialize(BYTE pdrv) {
    
}

/*!
 *  @brief Disk status getter
 *
 *  @param[in] pdrv : Physical drive number indicating type of drive, 1 == MMC
 *
 *  @return Status of disk as a DSTATUS code
 */
DSTATUS disk_status (BYTE pdrv) {
    // disk type other than SD/MMC not supported on ACE3.0
    if (pdrv != DEV_MMC)
        return STA_NOINIT;
    
    return dstat;
}

/*!
 *  @brief Read data from storage device
 *
 *  @param[in]  pdrv    : Physical drive number indicating type of drive, 1 == MMC
 *  @param[out] buff    : Pointer to the external buffer to read data into
 *  @param[in]  sector  : Start sector number
 *  @param[in]  count   : Number of sectors to read
 *
 *  @return Status of disk as a DSTATUS code
 */
DRESULT disk_read (
    BYTE pdrv,
    BYTE* buff,
    LBA_t sector,
    UINT count
) {
    // TODO: implement

    return RES_ERROR;
}


/*!
 *  @brief Read data from storage device
 *
 *  @param[in]  pdrv    : Physical drive number indicating type of drive, 1 == MMC
 *  @param[in]  buff    : Pointer to the external buffer to write data from
 *  @param[in]  sector  : Start sector number
 *  @param[in]  count   : Number of sectors to read
 *
 *  @return Status of disk as a DSTATUS code
 */
DRESULT disk_write (
    BYTE pdrv,
    const BYTE* buff,
    LBA_t sector,
    UINT count
) {
    // TODO: implement

    return RES_ERROR;
}


/*!
 *  @brief Read data from storage device
 *
 *  @param[in]  pdrv    : Physical drive number indicating type of drive, 1 == MMC
 *  @param[in]  cmd     : Control command code
 *
 *  @return Status of disk as a DSTATUS code
 */
DRESULT disk_ioctl (
    BYTE pdrv,
    BYTE cmd,
    void* buff
) {
    // TODO: implement

    return RES_ERROR;
}


#if !FF_FS_READONLY && !FF_FS_NORTC
/*!
 *  @brief Return current real time
 *
 *  @return Returns 0 since due to no RTC support on ACE3.0
 */
DWORD get_fattime (void) {
    return (uint32_t)0;
}
#endif