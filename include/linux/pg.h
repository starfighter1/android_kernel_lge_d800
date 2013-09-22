/* 	pg.h (c) 1998  Grant R. Guenther <grant@torque.net>
 		       Under the terms of the GNU General Public License


	pg.h defines the user interface to the generic ATAPI packet
        command driver for parallel port ATAPI devices (pg). The
	driver is loosely modelled after the generic SCSI driver, sg,
	although the actual interface is different.

	The pg driver provides a simple character device interface for
        sending ATAPI commands to a device.  With the exception of the
	ATAPI reset operation, all operations are performed by a pair
        of read and write operations to the appropriate /dev/pgN device.
	A write operation delivers a command and any outbound data in
        a single buffer.  Normally, the write will succeed unless the
        device is offline or malfunctioning, or there is already another
	command pending.  If the write succeeds, it should be followed
        immediately by a read operation, to obtain any returned data and
        status information.  A read will fail if there is no operation
        in progress.

	As a special case, the device can be reset with a write operation,
        and in this case, no following read is expected, or permitted.

	There are no ioctl() operations.  Any single operation
	may transfer at most PG_MAX_DATA bytes.  Note that the driver must
        copy the data through an internal buffer.  In keeping with all
	current ATAPI devices, command packets are assumed to be exactly
	12 bytes in length.

	To permit future changes to this interface, the headers in the
	read and write buffers contain a single character "magic" flag.
        Currently this flag must be the character "P".

*/

#define PG_MAGIC	'P'
#define PG_RESET	'Z'
#define PG_COMMAND	'C'

#define PG_MAX_DATA	32768

struct pg_write_hdr {

	char	magic;		/*             */
	char	func;		/*                        */
	int     dlen;		/*                                      */
	int     timeout;	/*                                  */
	char	packet[12];	/*                */

};

struct pg_read_hdr {

	char	magic;		/*             */
	char	scsi;		/*                            */
	int	dlen;		/*                                 */
	int     duration;	/*                              */
	char    pad[12];	/*          */

};

/*             */
