#define I2C_DEV_LOC     (0x2A)
#define INTB_PIN        (18)

#define STAT_REG        (0x00)
#define RDY_TO_WRITE    (1 << 5)
#define OUT_REG         (0x01)
#define DATAX_LSB       (0x02)
#define DATAX_MSB       (0x03)
#define DATA0_LSB       (0x02)
#define DATA0_MSB       (0x03)
#define DATA1_LSB       (0x04)
#define DATA1_MSB       (0x05)
#define DATA2_LSB       (0x06)
#define DATA2_MSB       (0x07)
#define DATA3_LSB       (0x08)
#define DATA3_MSB       (0x09)
#define RESET_REG       (0x0A)
#define CONFIG_MODE_ON  (0x01)
#define CONFIG_MODE_OFF (0x00)
#define EN_REG          (0x0C)
#define NP_SCAN_RATE    (0x0D)
#define GAIN0_REG       (0x0E)
#define LP_SCAN_RATE    (0x0F)
#define GAIN1_REG       (0x10)
#define INTPOL_REG      (0x11)
#define GAIN2_REG       (0x12)
#define LP_BASE_INC     (0x13)
#define GAIN3_REG       (0x14)
#define NP_BASE_INC     (0x15)
#define BT_PAUSE_MAXWIN (0x16)
#define LC_DIVIDER_REG  (0x17)
#define HYST_REG        (0x18)
#define TWIST_REG       (0x19)
#define COMMON_DEFORM   (0x1A)
#define ODOL_DPOL       (0x1C)
#define CNTSC_REG       (0x1E)
#define SENSOR0_CONFIG  (0x20)
#define SENSOR1_CONFIG  (0x22)
#define SENSOR2_CONFIG  (0x24)
#define SENSOR3_CONFIG  (0x26)
#define FTF1_2_REG      (0x28)
#define FTF3_REG        (0x2B)

#define CH1EN           (0x01)
#define CH2EN           (0x02)
#define CH3EN           (0x04)
#define CH4EN           (0x08)
