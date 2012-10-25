#ifndef __LW_SD_H__
#define __LW_SD_H__

#include <stdint.h>
#include <stdbool.h>

/* SD����Ϣ�ṹ�嶨�� */    
/* the information structure variable of SD Card*/          
typedef struct SD_STRUCT
{   
	uint8_t card_type;
	uint32_t block_num;   /* ���п������ */
	uint32_t block_len;   /* ���Ŀ鳤��(��λ:�ֽ�) */
	uint32_t erase_unit;  /* һ�οɲ����Ŀ���� */
	      
	uint32_t timeout_read;    /* ���鳬ʱʱ��(��λ: 8 SPI clock) */
	uint32_t timeout_write;   /* д�鳬ʱʱ��(��λ: 8 SPI clock) */
	uint32_t timeout_erase;   /* ���鳬ʱʱ��(��λ: 8 SPI clock) */    
}sd_struct;

extern sd_struct sd_info;

#define   CARDTYPE_SD       0x00    // ����ΪSD  ��
#define   CARDTYPE_MMC      0x01    // ����ΪMMC ��


/* ������ error code */
#define   SD_NO_ERR     0x00    // ����ִ�гɹ�
#define   SD_ERR_NO_CARD    0x01    // ��û����ȫ���뵽������
#define   SD_ERR_USER_PARAM     0x02    // �û�ʹ��API����ʱ����ڲ����д���
#define   SD_ERR_CARD_PARAM 0x03    // ���в����д����뱾ģ�鲻���ݣ�
#define   SD_ERR_VOL_NOTSUSP    0x04    // ����֧��3.3V����
#define   SD_ERR_OVER_CARDRANGE 0x05    // ����������������Χ
#define   SD_ERR_UNKNOWN_CARD   0x06    // �޷�ʶ����
                
/* SD������ܷ��صĴ����� */
#define   SD_ERR_CMD_RESPTYPE   0x10    // �������ʹ���
#define   SD_ERR_CMD_TIMEOUT    0x11    // ��������Ӧ��ʱ
#define   SD_ERR_CMD_RESP   0x12    // ��������Ӧ����
            
/* ������������ */
#define   SD_ERR_DATA_CRC16     0x20    // ������CRC16У�鲻ͨ��
#define   SD_ERR_DATA_START_TOK 0x21    // ���������ʱ�����ݿ�ʼ���Ʋ���ȷ
#define   SD_ERR_DATA_RESP  0x22    // д�������ʱ����������Ӧ���Ʋ���ȷ

/* �ȴ������� */
#define   SD_ERR_TIMEOUT_WAIT   0x30    // д�������ʱ��������ʱ����
#define   SD_ERR_TIMEOUT_READ   0x31    // ��������ʱ����
#define   SD_ERR_TIMEOUT_WRITE  0x32    // д������ʱ����   
#define   SD_ERR_TIMEOUT_ERASE  0x33    // ����������ʱ����
#define   SD_ERR_TIMEOUT_WAITIDLE 0x34  // ��ʼ����ʱ���ȴ����˳�����״̬��ʱ����
        
/* д�������ܷ��صĴ����� */
#define   SD_ERR_WRITE_BLK  0x40    // д�����ݴ���
#define   SD_ERR_WRITE_BLKNUMS  0x41    // д���ʱ����Ҫд��Ŀ�����ȷд��Ŀ�����һ��
#define   SD_ERR_WRITE_PROTECT  0x42    // ����ǵ�д�������ش���д����λ��




/* �����ڳ�ʼ���׶�,�ȴ�SD���˳�����״̬�����Դ��� */
/* Number of tries to wait for the card to go idle during initialization */
#define SD_IDLE_WAIT_MAX  1000

int32_t lw_sd_init(void);
int32_t lw_sd_active(void);
int32_t lw_sd_fatfs_init(void);
int32_t lw_sd_fatfs_deinit(void);
int32_t lw_get_frame2sd(void);

#endif

