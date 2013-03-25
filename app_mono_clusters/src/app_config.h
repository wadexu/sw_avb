#ifndef __app_config_h__
#define __app_config_h__

/***** APPLICATION CONFIGURATION ******/

/** Global switch to enable or disable AVB Talker functionality in the demo */
#define AVB_DEMO_ENABLE_TALKER 1
/** Global switch to enable or disable AVB Listener functionality in the demo */
#define AVB_DEMO_ENABLE_LISTENER 1

/** Number of input/output audio channels in the demo application 
  * For simplicity, input and output is identical in size but can be configured
  * differently in ``avb_conf.h``. */
#define AVB_DEMO_NUM_CHANNELS 2

#define AEM_GENERATE_CLUSTERS_MAP_ON_FLY 0

#define AVB_1722_1_ADP_ENTITY_CAPABILITIES (AVB_1722_1_ADP_ENTITY_CAPABILITIES_AEM_SUPPORTED|AVB_1722_1_ADP_ENTITY_CAPABILITIES_CLASS_A_SUPPORTED|AVB_1722_1_ADP_ENTITY_CAPABILITIES_GPTP_SUPPORTED|AVB_1722_1_ADP_ENTITY_CAPABILITIES_AEM_IDENTIFY_CONTROL_INDEX_VALID|AVB_1722_1_ADP_ENTITY_CAPABILITIES_AEM_INTERFACE_INDEX_VALID)

#define AVB_1722_1_ADP_ENTITY_MODEL_ID 0x00229700000000012llu

#define DESCRIPTOR_INDEX_CONTROL_IDENTIFY	0
#define DESCRIPTOR_INDEX_AVB_INTERFACE	0

/***** PORTS *********/

// This include fill will get included if you use a XMOS development target
// e.g. the XR-AVB-LC-BRD avb kit or the XMOS sliceKIT and set
// all the port defines accordingly

#ifdef __avb_app_board_config_h_exists__
#include "avb_app_board_config.h"
#endif

// If you are not using a standard dev board (e.g. creating an application for
// your own board), you can update the port mappings here



#define I2S_CLK_1 XS1_CLKBLK_3
#define I2S_CLK_2 XS1_CLKBLK_4

#if !USING_XMOS_DEV_BOARD

#define ETHERNET_PHY_ADDRESS 0

#define PORT_ETH_RXCLK     on tile[1]: XS1_PORT_1A
#define PORT_ETH_ERR       on tile[1]: XS1_PORT_1B
#define PORT_ETH_RXD       on tile[1]  XS1_PORT_4C
#define PORT_ETH_RXDV      on tile[1]: XS1_PORT_1D
#define PORT_ETH_TXCLK     on tile[1]: XS1_PORT_1C
#define PORT_ETH_TXEN      on tile[1]: XS1_PORT_1E
#define PORT_ETH_TXD       on tile[1]: XS1_PORT_4D

// ETHERNET_PORTS
#define ETHERNET_MII_INIT_full \
   { ETHERNET_CLKBLK_0, ETHERNET_CLKBLK_1, \
     PORT_ETH_RXCLK, PORT_ETH_ERR, PORT_ETH_RXD, PORT_ETH_RXDV, \
     PORT_ETH_TXCLK, PORT_ETH_TXEN, PORT_ETH_TXD }

#if SMI_COMBINE_MDC_MDIO
#define PORT_ETH_MDIOC
#define ETHERNET_SMI_INIT {ETHERNET_PHY_ADDRESS, \
                           PORT_ETH_MDIOC}
#else
#define PORT_ETH_MDIO     on tile[1]:XS1_PORT_1G
#define PORT_ETH_MDC      on tile[1]:XS1_PORT_1G
#define ETHERNET_SMI_INIT {ETHERNET_PHY_ADDRESS, \
                           PORT_ETH_MDIO,                \
                           PORT_ETH_MDC}
#endif

// CODEC control ports
#define PORT_I2C_SCL      on tile[1]:XS1_PORT_1L
#define PORT_I2C_SDA      on tile[1]:XS1_PORT_1K

// PLL frequency control
#define PORT_SYNC_OUT     on tile[0]:XS1_PORT_1E

// I2S ports
#define PORT_MCLK         on tile[0]:XS1_PORT_1K
#define PORT_SCLK         on tile[0]:XS1_PORT_1F
#define PORT_LRCLK        on tile[0]:XS1_PORT_1L

#define USER_PORT_SDATA_OUT    {on tile[0]:XS1_PORT_1G}
//,on tile[0]:XS1_PORT_1H,on tile[0]:XS1_PORT_1I,on tile[0]:XS1_PORT_1J}

#define PORT_SDATA_OUT       USER_PORT_SDATA_OUT

#define USER_PORT_SDATA_IN     {on tile[0]:XS1_PORT_1M}
//,on tile[0]:XS1_PORT_1N,on tile[0]:XS1_PORT_1O,on tile[0]:XS1_PORT_1P}

#define PORT_SDATA_IN       USER_PORT_SDATA_IN

#define USER_PORT_BUTTONS     on tile[1]:XS1_PORT_4A
#define PORT_BUTTONS USER_PORT_BUTTONS

#define USER_PORT_MUTE_LED_REMOTE  on tile[1]:XS1_PORT_4E
#define PORT_MUTE_LED_REMOTE USER_PORT_MUTE_LED_REMOTE

#define USER_PORT_LEDS  on tile[1]:XS1_PORT_4F
#define PORT_LEDS USER_PORT_LEDS

#define USER_PORT_GPIO		{on tile[0]:XS1_PORT_1H,on tile[0]:XS1_PORT_1I,on tile[0]:XS1_PORT_1J, on tile[0]:XS1_PORT_1N,on tile[0]:XS1_PORT_1O,on tile[0]:XS1_PORT_1P}
#define PORT_GPIO	USER_PORT_GPIO

#endif // !USING_XMOS_DEV_BOARD




#endif // __app_config_h__
