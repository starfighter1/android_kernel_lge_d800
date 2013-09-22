/*****************************************************************************
 Copyright(c) 2009 FCI Inc. All Rights Reserved
 
 File name : fc8000_hal.h
 
 Description : fc8000 host interface header
 
 History : 
 ----------------------------------------------------------------------
 2009/08/29 	jason		initial
*******************************************************************************/

#ifndef __FCI_HAL_H__
#define __FCI_HAL_H__

#ifdef __cplusplus
extern "C" {
#endif

extern int bbm_hostif_select(HANDLE hDevice, fci_u8 hostif);
extern int bbm_hostif_deselect(HANDLE hDevice);
extern int bbm_hostif_get(HANDLE hDevice, fci_u8 *hostif);

extern int bbm_read(HANDLE hDevice, fci_u16 addr, fci_u8 *data);
extern int bbm_byte_read(HANDLE hDevice, fci_u16 addr, fci_u8 *data);
extern int bbm_word_read(HANDLE hDevice, fci_u16 addr, fci_u16 *data);
extern int bbm_long_read(HANDLE hDevice, fci_u16 addr, fci_u32 *data);
extern int bbm_bulk_read(HANDLE hDevice, fci_u16 addr, fci_u8* data, fci_u16 length);

extern int bbm_write(HANDLE hDevice, fci_u16 addr, fci_u8 data);
extern int bbm_byte_write(HANDLE hDevice, fci_u16 addr, fci_u8 data);
extern int bbm_word_write(HANDLE hDevice, fci_u16 addr, fci_u16 data);
extern int bbm_long_write(HANDLE hDevice, fci_u16 addr, fci_u32 data);
extern int bbm_bulk_write(HANDLE hDevice, fci_u16 addr, fci_u8* data, fci_u16 length);

extern int bbm_data(HANDLE hDevice, fci_u16 addr, fci_u8* data, fci_u16 length);

#ifdef __cplusplus
}
#endif

#endif		//              
