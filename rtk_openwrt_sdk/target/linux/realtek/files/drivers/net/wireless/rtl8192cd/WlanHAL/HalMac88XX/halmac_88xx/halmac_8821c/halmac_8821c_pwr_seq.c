/*++
 * Copyright (c) Realtek Semiconductor Corp. All rights reserved.
 *
 * Module Name:
 *      Hal8821CPwrSeq.c
 *
 * Abstract:
 *      This file includes all kinds of Power Action event for RTL8821C and corresponding hardware configurtions which are released from HW SD.
 *
 * Major Change History:
 *      When       Who               What
 *      ---------- ---------------   -------------------------------
 *      2014-01-17 JackieLau            Create.
 *
 * --*/

#include "../halmac_88xx_cfg.h"
#include "halmac_8821c_cfg.h"


/*
 * drivers should parse below arrays and do the corresponding actions
 */

/* Power on  Array */
HALMAC_WLAN_PWR_CFG halmac_8821c_power_on_flow[HALMAC_8821c_TRANS_CARDEMU_TO_ACT_STEPS + HALMAC_8821c_TRANS_END_STEPS] = {
	HALMAC_RTL8821c_TRANS_CARDEMU_TO_ACT
	HALMAC_RTL8821c_TRANS_END
};

/* Radio off GPIO Array */
HALMAC_WLAN_PWR_CFG halmac_8821c_radio_off_flow[HALMAC_8821c_TRANS_ACT_TO_CARDEMU_STEPS + HALMAC_8821c_TRANS_END_STEPS] = {
	HALMAC_RTL8821c_TRANS_ACT_TO_CARDEMU
	HALMAC_RTL8821c_TRANS_END
};

/* Card Disable Array */
HALMAC_WLAN_PWR_CFG halmac_8821c_card_disable_flow[HALMAC_8821c_TRANS_ACT_TO_CARDEMU_STEPS + HALMAC_8821c_TRANS_CARDEMU_TO_PDN_STEPS + HALMAC_8821c_TRANS_END_STEPS] = {
	HALMAC_RTL8821c_TRANS_ACT_TO_CARDEMU
	HALMAC_RTL8821c_TRANS_CARDEMU_TO_CARDDIS
	HALMAC_RTL8821c_TRANS_END
};

/* Card Enable Array */
HALMAC_WLAN_PWR_CFG halmac_8821c_card_enable_flow[HALMAC_8821c_TRANS_ACT_TO_CARDEMU_STEPS + HALMAC_8821c_TRANS_CARDEMU_TO_PDN_STEPS + HALMAC_8821c_TRANS_END_STEPS] = {
	HALMAC_RTL8821c_TRANS_CARDDIS_TO_CARDEMU
	HALMAC_RTL8821c_TRANS_CARDEMU_TO_ACT
	HALMAC_RTL8821c_TRANS_END
};

/* Suspend Array */
HALMAC_WLAN_PWR_CFG halmac_8821c_suspend_flow[HALMAC_8821c_TRANS_ACT_TO_CARDEMU_STEPS + HALMAC_8821c_TRANS_CARDEMU_TO_SUS_STEPS + HALMAC_8821c_TRANS_END_STEPS] = {
	HALMAC_RTL8821c_TRANS_ACT_TO_CARDEMU
	HALMAC_RTL8821c_TRANS_CARDEMU_TO_SUS
	HALMAC_RTL8821c_TRANS_END
};

/* Resume Array */
HALMAC_WLAN_PWR_CFG halmac_8821c_resume_flow[HALMAC_8821c_TRANS_ACT_TO_CARDEMU_STEPS + HALMAC_8821c_TRANS_CARDEMU_TO_SUS_STEPS + HALMAC_8821c_TRANS_END_STEPS] = {
	HALMAC_RTL8821c_TRANS_SUS_TO_CARDEMU
	HALMAC_RTL8821c_TRANS_CARDEMU_TO_ACT
	HALMAC_RTL8821c_TRANS_END
};



/* HWPDN Array */
HALMAC_WLAN_PWR_CFG halmac_8821c_hwpdn_flow[HALMAC_8821c_TRANS_ACT_TO_CARDEMU_STEPS + HALMAC_8821c_TRANS_CARDEMU_TO_PDN_STEPS + HALMAC_8821c_TRANS_END_STEPS] = {
	/* TRANS_ACT_TO_CARDEMU */
	/* TRANS_CARDEMU_TO_PDN */
	/* HW behavior */
	HALMAC_RTL8821c_TRANS_END
};

/* Enter LPS */
HALMAC_WLAN_PWR_CFG halmac_8821c_enter_lps_flow[HALMAC_8821c_TRANS_ACT_TO_LPS_STEPS + HALMAC_8821c_TRANS_END_STEPS] = {
	/* FW behavior */
	HALMAC_RTL8821c_TRANS_ACT_TO_LPS
	HALMAC_RTL8821c_TRANS_END
};
/* Enter Deep LPS */
HALMAC_WLAN_PWR_CFG halmac_8821c_enter_deep_lps_flow[HALMAC_8821c_TRANS_ACT_TO_DEEP_LPS_STEPS + HALMAC_8821c_TRANS_END_STEPS] = {
	/* FW behavior */
	HALMAC_RTL8821c_TRANS_ACT_TO_DEEP_LPS
	HALMAC_RTL8821c_TRANS_END
};
/* Leave LPS */
HALMAC_WLAN_PWR_CFG halmac_8821c_leave_lps_flow[HALMAC_8821c_TRANS_LPS_TO_ACT_STEPS + HALMAC_8821c_TRANS_END_STEPS] = {
	/* FW behavior */
	HALMAC_RTL8821c_TRANS_LPS_TO_ACT
	HALMAC_RTL8821c_TRANS_END
};