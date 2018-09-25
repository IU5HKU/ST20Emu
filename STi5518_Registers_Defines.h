//st20emu COMPUTER GENERATED STi5518 INCLUDE FILE
//NUMBER of DEFINES CREATED: 1044

#define VID_CFG_MCF 0x00000000 //bits:7 Access:R/W DESCR:Memory refresh interval
#define VID_CFG_CCF 0x00000001 //bits:7 Access:R/W DESCR:Chip configuration
#define VID_CTL 0x00000002 //bits:5 Access:R/W DESCR:Decoding Control
#define VID_TIS 0x00000003 //bits:6 Access:W DESCR:Task Instruction
#define VID_PFH 0x00000004 //bits:8 Access:R/W DESCR:Picture F-parameters Horizontal
#define VID_PFV 0x00000005 //bits:8 Access:R/W DESCR:Picture F-parameters Vertical
#define VID_PPR1 0x00000006 //bits:7 Access:R/W DESCR:Picture Parameters 1
#define VID_PPR2 0x00000007 //bits:7 Access:R/W DESCR:Picture Parameters 2
#define USD_BMS_15_0 0x00000009 //bits:8 Access:R/W DESCR:Block move size
#define VID_DFP_14_8 0x0000000c //bits:7 Access:R/W DESCR:Displayed Luma Frame Pointer
#define VID_DFP_7_0 0x0000000d //bits:8 Access:R/W DESCR:Displayed Luma Frame Pointer
#define VID_RFP_14_8 0x0000000e //bits:7 Access:R/W DESCR:Reconstructed Frame Pointer
#define VID_RFP_7_0 0x0000000f //bits:8 Access:R/W DESCR:Reconstructed Frame Pointer
#define VID_FFP_13_8 0x00000010 //bits:6 Access:R/W DESCR:Forward Luma Frame Pointer
#define VID_FFP_7_0 0x00000011 //bits:8 Access:R/W DESCR:Forward Luma Frame Pointer
#define VID_BFP_14_8 0x00000012 //bits:7 Access:R/W DESCR:Backward Frame Pointer
#define VID_BFP7_0 0x00000013 //bits:8 Access:R/W DESCR:Backward Frame Pointer
#define VID_VBG_14_8 0x00000014 //bits:7 Access:R/W DESCR:Start of Video Bit Buffer
#define VID_VBG_7_0 0x00000015 //bits:8 Access:R/W DESCR:Start of Video Bit Buffer
#define VID_VBL_14_8 0x00000016 //bits:7 Access:R DESCR:Video Bit Buffer Level
#define VID_VBL_7_0 0x00000017 //bits:8 Access:R DESCR:Video Bit Buffer Level
#define VID_VBS_14_8 0x00000018 //bits:7 Access:R/W DESCR:Video Bit Buffer Stop
#define VID_VBS_7_0 0x00000019 //bits:8 Access:R/W DESCR:Video Bit Buffer Stop
#define VID_VBT_14_8 0x0000001a //bits:7 Access:R/W DESCR:Video Bit Buffer Threshold
#define VID_VBT_7_0 0x0000001b //bits:8 Access:R/W DESCR:Video Bit Buffer Threshold
#define VID_ABG_14_8 0x0000001c //bits:7 Access:R/W DESCR:Start of audio bit buffer
#define VID_ABG_7_0 0x0000001d //bits:8 Access:R/W DESCR:Start of audio bit buffer
#define VID_ABL_14_8 0x0000001e //bits:7 Access:R DESCR:Audio Bit Buffer Level
#define VID_ABL_7_0 0x0000001f //bits:8 Access:R DESCR:Audio Bit Buffer Level
#define VID_ABS_14_8 0x00000020 //bits:7 Access:R/W DESCR:Audio Bit Buffer Stop
#define VID_ABS_7_0 0x00000021 //bits:8 Access:R/W DESCR:Audio Bit Buffer Stop
#define VID_ABT_14_8 0x00000022 //bits:7 Access:R/W DESCR:Audio Bit Buffer Threshold
#define VID_ABT_7_0 0x00000023 //bits:8 Access:R/W DESCR:Audio Bit Buffer Threshold
#define VID_DFS 0x00000024 //bits:15 Access:R/W DESCR:Serial Decoded Frame Size
#define VID_DFW 0x00000025 //bits:8 Access:R/W DESCR:Decoded Frame Width
#define VID_XFW 0x00000028 //bits:8 Access:R/W DESCR:Displayed Frame Width
#define OSD_OTP 0x0000002a //bits:14 Access:Serial R/W DESCR:OSD Top Field Pointer
#define OSD_OBP 0x0000002b //bits:14 Access:Serial R/W DESCR:OSD Bottom Field Pointer
#define VID_PAN_10_8 0x0000002c //bits:3 Access:R/W DESCR:Pan/scan horizontal vector integer part
#define VID_PAN_7_0 0x0000002d //bits:8 Access:R/W DESCR:Pan/scan horizontal vector integer part
#define VID_PTH_13_8 0x0000002e //bits:6 Access:R/W DESCR:Panic threshold
#define VID_PTH_7_0 0x0000002f //bits:8 Access:R/W DESCR:Panic threshold
#define VID_STL 0x00000030 //bits:2 Access:R/W DESCR:Launch start-code detector FIFO
#define VID_CWL 0x00000031 //bits:1 Access:R/W DESCR:Launch compress data write
#define VID_656 0x00000032 //bits:1 Access:R/W DESCR:Enable 656 mode
#define VID_SRA 0x00000035 //bits:1 Access:R/W DESCR:Audio Soft Reset
#define VID_CFG_DRC 0x00000038 //bits:6 Access:R/W DESCR:SDRAM configuration
#define VID_SRV 0x00000039 //bits:1 Access:R/W DESCR:Video Soft Reset
#define VID_CFG_GCF 0x0000003a //bits:8 Access:R/W DESCR:General configuration
#define VID_STA 0x0000003b //bits:8 Access:R DESCR:Status
#define VID_ITM 0x0000003c //bits:8 Access:R/W DESCR:Interrupt Mask
#define VID_ITS 0x0000003d //bits:8 Access:R DESCR:Interrupt Status
#define OSD_ACT 0x0000003e //bits:7 Access:R/W DESCR:Active Signal
#define VID_TP_VID_LDP 0x0000003f //bits:3 Access:R/W DESCR:Load Pointer
#define PES_CF1 0x00000040 //bits:7 Access:R/W DESCR:PES Audio Decoding Control
#define PES_CF2 0x00000041 //bits:8 Access:R/W DESCR:PES Video Parser Control
#define PES_TM1 0x00000042 //bits:8 Access:RO DESCR:DSM Trick Mode
#define PES_TM2 0x00000043 //bits:2 Access:RO DESCR:PES Parser Status
#define VID_YDS_8 0x00000046 //bits:1 Access:R/W DESCR:Display Y End
#define VID_YDS_7_0 0x00000047 //bits:8 Access:R/W DESCR:Display Y End
#define PES_TS_7_0 0x00000049 //bits:8 Access:RO DESCR:PES Time Stamps
#define PES_TS_15_8 0x0000004a //bits:8 Access:RO DESCR:PES Time Stamps
#define PES_TS_23_16 0x0000004b //bits:8 Access:RO DESCR:PES Time Stamps
#define PES_TS_31_24 0x0000004c //bits:8 Access:RO DESCR:PES Time Stamps
#define PES_TS_32_TSA 0x0000004d //bits:2 Access:RO DESCR:PES Time Stamps
#define VID_SPREAD 0x0000004e //bits:20 Access:R/W DESCR:Serial Sub-picture Read Pointer
#define VID_SPWRITE 0x0000004f //bits:20 Access:R/W DESCR:Serial Sub-picture Write Pointer
#define VID_SPB_10_8 0x00000050 //bits:3 Access:R/W DESCR:Sub-picture Buffer Begin
#define VID_SPB_7_0 0x00000051 //bits:8 Access:R/W DESCR:Sub-picture Buffer Begin
#define VID_SPE_11_8 0x00000052 //bits:4 Access:R/W DESCR:Sub-picture Buffer End
#define VID_SPE_7_0 0x00000053 //bits:8 Access:R/W DESCR:Sub-picture Buffer End
#define VID_TRF_12_8 0x00000056 //bits:4 Access:R/W DESCR:Temporal Reference
#define VID_TRF_7_0 0x00000057 //bits:8 Access:R/W DESCR:Temporal Reference
#define VID_DFC_14_8 0x00000058 //bits:7 Access:R/W DESCR:Displayed Chroma Frame Pointer
#define VID_DFC_7_0 0x00000059 //bits:8 Access:R/W DESCR:Displayed Chroma Frame Pointer
#define VID_RFC_14_8 0x0000005a //bits:7 Access:R/W DESCR:Reconstructed Chroma Frame Pointer
#define VID_RFC_7_0 0x0000005b //bits:8 Access:R/W DESCR:Reconstructed Chroma Frame Pointer
#define VID_FFC_14_8 0x0000005c //bits:7 Access:R/W DESCR:Forward Chroma Frame Pointer
#define VID_FFC_7_0 0x0000005d //bits:8 Access:R/W DESCR:Forward Chroma Frame Pointer
#define VID_BFC_14_8 0x0000005e //bits:7 Access:R/W DESCR:Backward Chroma Pointer
#define VID_BFC_7_0 0x0000005f //bits:8 Access:R/W DESCR:Backward Chroma Pointer
#define VID_ITM1 0x00000060 //bits:8 Access:R/W DESCR:Interrupt Mask
#define VID_ITM2 0x00000061 //bits:8 Access:R/W DESCR:Interrupt Mask
#define VID_ITS1 0x00000062 //bits:8 Access:R DESCR:Interrupt Status
#define VID_ITS2 0x00000063 //bits:8 Access:R DESCR:Interrupt Status
#define VID_STA2 0x00000064 //bits:8 Access:R DESCR:Status
#define VID_STA3 0x00000065 //bits:8 Access:R DESCR:Status
#define VID_HDF 0x00000066 //bits:16 Access:R DESCR:Serial Header Data FIFO
#define VID_CDCOUNT 0x00000067 //bits:24 Access:R DESCR:Serial Bit Buffer Input Counter
#define VID_SCDCOUNT 0x00000068 //bits:24 Access:R DESCR:Serial Bit Buffer Output Counter
#define VID_HDS 0x00000069 //bits:4 Access:R/W DESCR:Header Search
#define VID_LSO 0x0000006a //bits:8 Access:R/W DESCR:SRC Luminance Offset
#define VID_LSR_7_0 0x0000006b //bits:8 Access:R/W DESCR:SRC Luma Resolution
#define VID_CSO 0x0000006c //bits:8 Access:R/W DESCR:SRC Chrominance Offset
#define VID_LSR_8 0x0000006d //bits:1 Access:R/W DESCR:SRC Luma Resolution
#define VID_YDO_8 0x0000006e //bits:1 Access:R/W DESCR:Display Y Offset
#define VID_YDO_7_0 0x0000006f //bits:8 Access:R/W DESCR:Display Y Offset
#define VID_XDO_9_8 0x00000070 //bits:2 Access:R/W DESCR:Display X Offset
#define VID_XDO_7_0 0x00000071 //bits:8 Access:R/W DESCR:Display X Offset
#define VID_XDS_9_8 0x00000072 //bits:2 Access:R/W DESCR:Display X End
#define VID_XDS_7_0 0x00000073 //bits:8 Access:R/W DESCR:Display X End
#define VID_DCF1 0x00000074 //bits:6 Access:R/W DESCR:Display Configuration
#define VID_DCF2 0x00000075 //bits:6 Access:R/W DESCR:Display Configuration
#define VID_QMW 0x00000076 //bits:8 Access:W DESCR:Quantization Matrix Data
#define VID_TST 0x00000077 //bits:1 Access:R/W DESCR:Test register
#define VID_REV 0x00000078 //bits:8 Access:R DESCR:Device revision
#define VID_LCK 0x0000007b //bits:1 Access:R/W DESCR:Locks registers VID_CFG_MCF, VID_CFG_CCF and VID_CFG_DRC
#define VID_TP_SCD_RD_15_8 0x00000081 //bits:8 Access:RO DESCR:Read only SCD pointer VLD load address
#define VID_TP_SCD_RD_7_0 0x00000082 //bits:8 Access:RO DESCR:Read only SCD pointer VLD load address
#define VID_TP_CD_RD_19_16 0x00000083 //bits:4 Access:RO DESCR:Read only CD pointer current address
#define VID_TP_CD_RD_15_8 0x00000084 //bits:8 Access:RO DESCR:Read only CD pointer current address
#define VID_TP_CD_RD_0_7 0x00000085 //bits:8 Access:RO DESCR:Read only CD pointer current address
#define VID_SCN 0x00000087 //bits:6 Access:R/W DESCR:Pan/Scan Vertical Vector
#define USD_BRP_19_16 0x00000088 //bits:4 Access:R/W DESCR:Memory Read Pointer
#define USD_BRP_15_8 0x00000089 //bits:8 Access:R/W DESCR:Memory Read Pointer
#define USD_BRP_7_0 0x0000008a //bits:8 Access:R/W DESCR:Memory Read Pointer
#define USD_BWP_19_16 0x0000008c //bits:4 Access:R/W DESCR:Memory write pointer
#define USD_BWP_15_8 0x0000008d //bits:8 Access:R/W DESCR:Memory write pointer
#define USD_BWP_7_0 0x0000008e //bits:8 Access:R/W DESCR:Memory write pointer
#define VID_OUT 0x00000090 //bits:4 Access:R/W DESCR:Output of 4:2:2 display
#define OSD_CFG 0x00000091 //bits:3 Access:R/W DESCR:OSD Configuration
#define OSD_BDW 0x00000092 //bits:6 Access:R/W DESCR:OSD Boundary Weight
#define VID_BCK_Y 0x00000098 //bits:8 Access:R/W DESCR:Background color Y
#define VID_BCK_V 0x00000099 //bits:8 Access:R/W DESCR:Background color V
#define VID_BCK_U 0x0000009a //bits:8 Access:R/W DESCR:Background color U
#define VID_MWV 0x0000009b //bits:8 Access:R/W DESCR:Color mix between background color and video
#define USD_BSK_19_16 0x000000a4 //bits:8 Access:R/W DESCR:Block skip
#define USD_BSK_15_8 0x000000a5 //bits:8 Access:R/W DESCR:Block skip
#define USD_BSK_7_0 0x000000a6 //bits:8 Access:R/W DESCR:Block skip
#define VID_TP_SCD_16 0x000000c0 //bits:1 Access:R/W DESCR:SCD pointer load address
#define VID_TP_SCD_15_8 0x000000c1 //bits:8 Access:R/W DESCR:SCD pointer load address
#define VID_TP_SCD_7_0 0x000000c2 //bits:8 Access:R/W DESCR:SCD pointer load address
#define VID_TP_VLD_RD_19_16 0x000000c3 //bits:4 Access:RO DESCR:Read only VLD pointer current address
#define VID_TP_VLD_RD_15_8 0x000000c4 //bits:8 Access:RO DESCR:Read only VLD pointer current address
#define VID_TP_VLD_RD_7_0 0x000000c5 //bits:8 Access:RO DESCR:Read only VLD pointer current address
#define VID_TP_CD_16 0x000000ca //bits:1 Access:R/W DESCR:CD pointer load address bit 16
#define VID_TP_CD_15_8 0x000000cb //bits:8 Access:R/W DESCR:CD pointer load address bits 15-8
#define VID_TP_CD_7_0 0x000000cc //bits:8 Access:R/W DESCR:CD pointer load address bits 0-7
#define VID_TP_SCD_CURRENT_19_16 0x000000cd //bits:4 Access:RO DESCR:Read only SCD pointer current address
#define VID_TP_SCD_CURRENT_15_8 0x000000ce //bits:8 Access:RO DESCR:Read only SCD pointer current address
#define VID_TP_SCD_CURRENT 0x000000cf //bits:8 Access:RO DESCR:Read only SCD pointer current address
#define VID_TP_VLD_15_8 0x000000d4 //bits:8 Access:R/W DESCR:VLD pointer load address
#define VID_TP_VLD_7_0 0x000000d5 //bits:8 Access:R/W DESCR:VLD pointer load address
#define VID_DCF 0x000000d6 //bits:3 Access:R/W DESCR:Display Configuration
#define VID_TP_CDLIMIT_16 0x000000e0 //bits:1 Access:R/W DESCR:CD write limit address
#define VID_TP_CDLIMIT_15_8 0x000000e1 //bits:8 Access:R/W DESCR:CD write limit address
#define VID_TP_CDLIMIT_7_0 0x000000e2 //bits:8 Access:R/W DESCR:CD write limit address
#define VID_CMOD 0x000000ea //bits:40 Access:R/W DESCR:to->0x000000EE Configure chrominance of block-row
#define VID_YMOD 0x000000ef //bits:40 Access:R/W DESCR:to->0x000000F3 Configure luminance of block-row
#define CKG_LPC_DIV 0x000001ce //bits:8 Access:R/W DESCR:Low-power clock divider
#define CKG_PLL_CNT 0x000001cf //bits:6 Access:R/W DESCR:Clock bypass PLL phase and PLL controller
#define CKG_CCAUD 0x000001d0 //bits:3 Access:R/W DESCR:Clock controller for audio clock
#define CKG_DIVAUD 0x000001d1 //bits:4 Access:R/W DESCR:Clock divider for audio clock
#define CKG_CCAUXDENC 0x000001d2 //bits:3 Access:R/W DESCR:Auxiliary clock controller
#define CKG_DIVAUXDENC 0x000001d3 //bits:4 Access:R/W DESCR:Denc Test clock divider
#define CKG_CCMCK 0x000001d4 //bits:3 Access:R/W DESCR:Clock controller for MEMCLK
#define CKG_DIVMCK 0x000001d5 //bits:4 Access:R/W DESCR:Clock divider for MEMCLK
#define CKG_SFREQSMC_SDIV 0x000001d6 //bits:3 Access:R/W DESCR:SDIV reg: SMC frequency synthesizer
#define CKG_SFREQSMC_PE0 0x000001d7 //bits:8 Access:R/W DESCR:PE reg (LSB): SMC frequency synthesizer
#define CKG_SFREQSMC_PE1 0x000001d8 //bits:8 Access:R/W DESCR:PE reg (MSB): SMC frequency synthesizer
#define CKG_SFREQSMC_MD 0x000001d9 //bits:5 Access:R/W DESCR:MD reg: SMC frequency synthesizer
#define CKG_SMC_CNT 0x000001da //bits:2 Access:R/W DESCR:Smart card clock control
#define CKG_CCDENC 0x000001dc //bits:3 Access:R/W DESCR:Clock Control for the DENC Clock
#define CKG_CCST20 0x000001dd //bits:3 Access:R/W DESCR:Clock controller for ST20 clock
#define CKG_DIVST20 0x000001de //bits:4 Access:R/W DESCR:Clock divider for ST20 clock
#define CKG_PREDIVPLL 0x000001df //bits:8 Access:R/W DESCR:Pre-divider ratio set-up of the PLL
#define CKG_FBKDIVPLL 0x000001e0 //bits:8 Access:R/W DESCR:Feedback divider ratio set-up of the PLL
#define CKG_POSTDIVPLL 0x000001e1 //bits:6 Access:R/W DESCR:Post divider ratio and lock detector
#define CKG_PLLSETUP 0x000001e2 //bits:6 Access:R/W DESCR:PLL start-up control and charge pump control
#define CKG_IDDQPAD_C 0x000001e3 //bits:4 Access:R/W DESCR:Iddq mode, I/O hsync, vsync
#define CKG_SFREQAUD_SDIV 0x000001e4 //bits:3 Access:R/W DESCR:SDIV reg: AUD frequency synthesizer
#define CKG_SFREQAUD_PE0 0x000001e5 //bits:8 Access:R/W DESCR:PE reg (LSB): AUD frequency synthesizer
#define CKG_SFREQAUD_PE1 0x000001e6 //bits:8 Access:R/W DESCR:PE reg (MSB): AUD frequency synthesizer
#define CKG_SFREQAUD_MD 0x000001e7 //bits:5 Access:R/W DESCR:MD reg: AUD frequency synthesizer
#define CKG_AUD_CNT 0x000001e8 //bits:1 Access:R/W DESCR:Sets audio frequency control through ST20 or MMDSP
#define CKG_SFREQAUX_SDIV 0x000001e9 //bits:3 Access:R/W DESCR:SDIV reg: AUX frequency synthesizer
#define CKG_SFREQAUX_PE0 0x000001ea //bits:8 Access:R/W DESCR:PE reg (LSB): AUX frequency synthesizer
#define CKG_SFREQAUX_PE1 0x000001eb //bits:8 Access:R/W DESCR:PE reg (MSB): AUX frequency synthesizer
#define CKG_SFREQAUX_MD 0x000001ec //bits:5 Access:R/W DESCR:MD reg: AUX frequency synthesizer
#define CKG_AUX_CNT 0x000001ed //bits:1 Access:R/W DESCR:Enable AUX frequency synthesizer
#define DEN_YCOUT 0x000001f9 //bits:1 Access:R/W DESCR:Make YC data bus accessible on PIO4
#define AUD_VERSION 0x00000200 //bits:8 Access:RO DESCR:Hardware version
#define AUD_IDENT 0x00000201 //bits:8 Access:RO DESCR:Identify
#define AUD_SFREQ 0x00000205 //bits:8 Access:R/W DESCR:Sampling frequency
#define AUD_EMPH 0x00000206 //bits:2 Access:R/W DESCR:Emphasis
#define AUD_INTEL_7_0 0x00000207 //bits:16 Access:R/W DESCR:Interrupt enable
#define AUD_INTE_15_8 0x00000208 //bits:16 Access:R/W DESCR:Interrupt enable
#define AUD_INT_7_0 0x00000209 //bits:16 Access:R/W DESCR:Interrupt
#define AUD_INT_15_8 0x0000020a //bits:16 Access:R/W DESCR:Interrupt
#define AUD_SIN_SETUP 0x0000020c //bits:8 Access:R/W DESCR:Input data setup
#define AUD_CAN_SETUP 0x0000020d //bits:8 Access:R/W DESCR:A/D converter setup
#define AUD_ERROR 0x0000020f //bits:8 Access:RO DESCR:ERROR code
#define AUD_SOFTRESET 0x00000210 //bits:8 Access:W DESCR:Soft reset
#define AUD_PLLPCM 0x00000212 //bits:3 Access:R/W DESCR:PCM PLL disable
#define AUD_PLAY 0x00000213 //bits:1 Access:R/W DESCR:Play
#define AUD_MUTE 0x00000214 //bits:1 Access:R/W DESCR:Mute
#define AUD_PLLMASK 0x00000218 //bits:1 Access:W DESCR:PCMCLK mask for half sampling frequency
#define AUD_SYNCSTATUS 0x00000240 //bits:4 Access:RO DESCR:Synchronization status
#define AUD_ANCCOUNT 0x00000241 //bits:8 Access:RO DESCR:Ancillary data
#define AUD_HEAD_31_24 0x00000242 //bits:8 Access:RO DESCR:HEADER 4 register
#define AUD_HEAD_23_16 0x00000243 //bits:8 Access:RO DESCR:HEADER 3 register
#define AUD_HEADLEN_15_8 0x00000244 //bits:8 Access:RO DESCR:Frame length
#define AUD_HEADLEN_7_0 0x00000245 //bits:8 Access:RO DESCR:Frame length
#define AUD_PTS_32 0x00000246 //bits:8 Access:R/W DESCR:PTS
#define AUD_PTS_31_24 0x00000247 //bits:8 Access:R/W DESCR:PTS
#define AUD_PTS_23_16 0x00000248 //bits:8 Access:R/W DESCR:PTS
#define AUD_PTS_15_8 0x00000249 //bits:8 Access:R/W DESCR:PTS
#define AUD_PTS_7_0 0x0000024a //bits:8 Access:R/W DESCR:PTS
#define AUD_STREAMSEL 0x0000024c //bits:3 Access:R/W DESCR:STREAM selection
#define AUD_DECODESEL 0x0000024d //bits:5 Access:R/W DESCR:Decoding algorithm
#define AUD_VOLUME0 0x0000024e //bits:8 Access:R/W DESCR:Left/right balance
#define AUD_PACKET_LOCK 0x0000024f //bits:8 Access:R/W DESCR:Packet lock
#define AUD_AUDIO_ID_EN 0x00000250 //bits:8 Access:R/W DESCR:Enable audio ID
#define AUD_AUDIO_ID 0x00000251 //bits:8 Access:R/W DESCR:Audio ID
#define AUD_AUDIO_ID_EXT 0x00000252 //bits:8 Access:R/W DESCR:Audio extension
#define AUD_SYNC_LOCK 0x00000253 //bits:8 Access:R/W DESCR:SYNC lock
#define AUD_PCMDIVIDER 0x00000254 //bits:8 Access:R/W DESCR:Divider for PCM clock
#define AUD_PCM_CONF 0x00000255 //bits:7 Access:R/W DESCR:PCM configuration
#define AUD_PCM_CROSS 0x00000256 //bits:6 Access:R/W DESCR:Cross PCM channels
#define AUD_LDLY_TM_SPEED 0x00000257 //bits:8 Access:R/W DESCR:Left channel - Audio trick-mode speed
#define AUD_RDLY 0x00000258 //bits:8 Access:R/W DESCR:Right channel
#define AUD_CDLY 0x00000259 //bits:8 Access:R/W DESCR:Centre channel
#define AUD_SUBDLY 0x0000025a //bits:8 Access:R/W DESCR:Subwoofer channel
#define AUD_LSDLY 0x0000025b //bits:8 Access:R/W DESCR:Left surround channel
#define AUD_RSDLY 0x0000025c //bits:8 Access:R/W DESCR:Right surround channel
#define AUD_DLYUPDATE 0x0000025d //bits:8 Access:R/W DESCR:PCM delay update
#define AUD_SPDIF_CMD 0x0000025e //bits:8 Access:R/W DESCR:IEC958 control
#define AUD_SPDIF_CAT 0x0000025f //bits:8 Access:R/W DESCR:Category code
#define AUD_SPDIF_CONF 0x00000260 //bits:8 Access:R/W DESCR:IEC958 PCMCLK divider
#define AUD_SPDIF_STATUS 0x00000261 //bits:7 Access:R/W DESCR:IEC status bit
#define AUD_PDEC 0x00000262 //bits:3 Access:R/W DESCR:Post decoder register
#define AUD_VOLUME1 0x00000263 //bits:8 Access:R/W DESCR:L/R surround balance
#define AUD_PL_AB 0x00000264 //bits:8 Access:R/W DESCR:Pro logic auto balance
#define AUD_PL_DWNX 0x00000265 //bits:8 Access:R/W DESCR:Pro logic decoder downmix
#define AUD_OCFG 0x00000266 //bits:4 Access:R/W DESCR:Output configuration
#define AUD_CHAN_IDX 0x00000267 //bits:3 Access:R/W DESCR:PCM scale factor
#define AUD_PCM_BTONE 0x00000268 //bits:8 Access:R/W DESCR:PCM beep tone frequency - Decode LFE for AC3 setup - Channel skip for MPEG setup
#define AUD_COMP_MOD 0x00000269 //bits:8 Access:R/W DESCR:Compression mode for AC3 setup - Program number for MPEG setup
#define AUD_AC3_HDR 0x0000026a //bits:8 Access:R/W DESCR:High dynamic range for AC3 setup - High dynamic range for MPEG setup
#define AUD_AC3_LDR 0x0000026b //bits:8 Access:R/W DESCR:Low dynamic range
#define AUD_AC3_CRC_OFF 0x0000026c //bits:8 Access:R/W DESCR:Repeat count for AC3 setup - CRC check-off for MPEG setup
#define AUD_AC3_KARAMODE 0x0000026d //bits:8 Access:R/W DESCR:Karaoke downmix for AC3 setup - Multichannel for MPEG setup
#define AUD_AC3_DUALMODE 0x0000026e //bits:8 Access:R/W DESCR:Dual downmix for AC3 setup - Dual downmix for MPEG setup
#define AUD_AC3_DOWNMIX 0x0000026f //bits:8 Access:R/W DESCR:Downmix for AC3 setup - Downmix for MPEG setup
#define AUD_DWSMODE 0x00000270 //bits:8 Access:R/W DESCR:Downsampling filter
#define AUD_SOFTVER 0x00000271 //bits:8 Access:R/W DESCR:Software version
#define AUD_RUN 0x00000272 //bits:1 Access:R/W DESCR:RUN decoding
#define AUD_SKIP_MUTE_CMD 0x00000273 //bits:5 Access:R/W DESCR:Skip or mute commands
#define AUD_SKIP_MUTE_VALUE 0x00000274 //bits:8 Access:R/W DESCR:Skip frames or mutes blocks of frame
#define AUD_SPDIF_REP_TIME 0x00000275 //bits:8 Access:R/W DESCR:IEC958 repetition time of a pause frame
#define AUD_STATUS0 0x00000276 //bits:8 Access:RO DESCR:AC-3 status register 0 - MPEG status register0
#define AUD_STATUS1 0x00000277 //bits:4 Access:RO DESCR:AC-3 status register 1 - MPEG status register1
#define AUD_STATUS2 0x00000278 //bits:8 Access:RO DESCR:AC-3 status register 2 - MPEG status register2
#define AUD_STATUS3 0x00000279 //bits:4 Access:RO DESCR:AC-3 status register 3 - MPEG status register3
#define AUD_STATUS4 0x0000027a //bits:5 Access:RO DESCR:AC-3 status register 4 - MPEG status register4
#define AUD_STATUS5 0x0000027b //bits:8 Access:RO DESCR:AC-3 status register 5 - MPEG status register5
#define AUD_STATUS6 0x0000027c //bits:5 Access:RO DESCR:AC-3 status register 6
#define AUD_STATUS7 0x0000027d //bits:8 Access:RO DESCR:AC-3 status register 7
#define AUD_SPDIF_LATENCY 0x0000027e //bits:8 Access:R/W DESCR:Latency value
#define AUD_SPDIF_DTDI 0x0000027f //bits:8 Access:R/W DESCR:IEC958 data type information
#define SPD_CTL1 0x00000400 //bits:6 Access:R/W DESCR:Control Register 1
#define SPD_SPR 0x00000401 //bits:1 Access:R/W DESCR:Soft Reset
#define SPD_CTL2 0x00000402 //bits:2 Access:R/W DESCR:Control Register 2
#define SPD_LUT 0x00000403 //bits:8 Access:W DESCR:Main Lookup Table
#define SPD_XD0_9_8 0x00000404 //bits:2 Access:R/W DESCR:Sub-picture X Offset
#define SPD_XD0_7_0 0x00000405 //bits:8 Access:R/W DESCR:Sub-picture X Offset
#define SPD_YD0_1_9_8 0x00000406 //bits:2 Access:R/W DESCR:Sub-picture Y Offset
#define SPD_YD0_2_7_0 0x00000407 //bits:8 Access:R/W DESCR:Sub-picture Y Offset
#define SPD_HLSX_9_8 0x0000040c //bits:2 Access:R/W DESCR:Highlight Region Start X
#define SPD_HLSX_7_0 0x0000040d //bits:8 Access:R/W DESCR:Highlight Region Start X
#define SPD_HLSY_9_8 0x0000040e //bits:2 Access:R/W DESCR:Highlight Region Start Y
#define SPD_HLSY_7_0 0x0000040f //bits:8 Access:R/W DESCR:Highlight Region Start Y
#define SPD_HLEX_9_8 0x00000410 //bits:2 Access:R/W DESCR:Highlight Region End X
#define SPD_HLEX_7_0 0x00000411 //bits:8 Access:R/W DESCR:Highlight Region End X
#define SPD_HLEY_9_8 0x00000412 //bits:2 Access:R/W DESCR:Highlight Region End Y
#define SPD_HLEY_7_0 0x00000413 //bits:8 Access:R/W DESCR:Highlight Region End Y
#define SPD_HCOL 0x00000414 //bits:8 Access:R/W DESCR:Highlight Region Color
#define SPD_HCOL 0x00000415 //bits:8 Access:R/W DESCR:Highlight Region Color
#define SPD_HCN 0x00000416 //bits:8 Access:R/W DESCR:Highlight Region Contrast
#define SPD_HCN 0x00000417 //bits:8 Access:R/W DESCR:Highlight Region Contrast
#define SPD_SXD0_9_8 0x00000424 //bits:2 Access:R/W DESCR:Sub-picture Display Area
#define SPD_SXD0_7_0 0x00000425 //bits:8 Access:R/W DESCR:Sub-picture Display Area
#define SPD_SYD0_9_8 0x00000426 //bits:2 Access:R/W DESCR:Sub-picture Display Area
#define SPD_SYD0_7_0 0x00000427 //bits:8 Access:R/W DESCR:Sub-picture Display Area
#define SPD_SXD1_9_8 0x00000428 //bits:2 Access:R/W DESCR:Sub-picture Display Area
#define SPD_SXD1_7_0 0x00000429 //bits:8 Access:R/W DESCR:Sub-picture Display Area
#define SPD_SYD1_9_8 0x0000042a //bits:2 Access:R/W DESCR:Sub-picture Display Area
#define SPD_SYD1_7_0 0x0000042b //bits:8 Access:R/W DESCR:Sub-picture Display Area
#define OGT_CTL 0x00000440 //bits:7 Access:R/W DESCR:Control register
#define OGT_LUT 0x00000441 //bits:8 Access:R/W DESCR:Main look-up table
#define OGT_LUT_H1 0x00000442 //bits:8 Access:R/W DESCR:Highlight 1 look-up table
#define OGT_LUT_H2 0x00000443 //bits:8 Access:R/W DESCR:Highlight 2 look-up table
#define OGT_XDI 0x00000444 //bits:2 Access:R/W DESCR:Active area horizontal position offset
#define OGT_XDI 0x00000445 //bits:8 Access:R/W DESCR:Active area horizontal position offset
#define OGT_YDI 0x00000446 //bits:2 Access:R/W DESCR:Active area vertical position offset
#define OGT_YDI 0x00000447 //bits:8 Access:R/W DESCR:Active area vertical position offset
#define OGT_HL2XO 0x00000448 //bits:2 Access:R/W DESCR:Active area vertical position offset
#define OGT_HL2XO 0x00000449 //bits:8 Access:R/W DESCR:Active area vertical position offset
#define OGT_HL2YO 0x0000044a //bits:2 Access:R/W DESCR:Highlight 2 area, start Y
#define OGT_HL2YO 0x0000044b //bits:8 Access:R/W DESCR:Highlight 2 area, start Y
#define OGT_HL2XI 0x0000044c //bits:2 Access:R/W DESCR:Highlight 2 area, end X
#define OGT_HL2XI 0x0000044d //bits:8 Access:R/W DESCR:Highlight 2 area, end X
#define OGT_HL2YI 0x0000044e //bits:2 Access:R/W DESCR:Highlight 2 area, end Y
#define OGT_HL2YI 0x0000044f //bits:8 Access:R/W DESCR:Highlight 2 area, end Y
#define OGT_STAT 0x00000450 //bits:2 Access:R DESCR:Status register
#define DEN_CFG0 0x00000600 //bits:8 Access:R/W DESCR:DENC configuration 0
#define DEN_CFG1 0x00000601 //bits:8 Access:R/W DESCR:DENC configuration 1
#define DEN_CFG2 0x00000602 //bits:8 Access:R/W DESCR:DENC configuration 2
#define DEN_CFG3 0x00000603 //bits:8 Access:R/W DESCR:DENC configuration 3
#define DEN_CFG4 0x00000604 //bits:8 Access:R/W DESCR:DENC configuration 4
#define DEN_CFG5 0x00000605 //bits:7 Access:R/W DESCR:DENC configuration 5
#define DEN_CFG6 0x00000606 //bits:8 Access:R/W DESCR:DENC configuration 6
#define DEN_CFG7 0x00000607 //bits:8 Access:R/W DESCR:DENC configuration 7
#define DEN_CFG8 0x00000608 //bits:8 Access:R/W DESCR:DENC configuration 8
#define DEN_STA 0x00000609 //bits:8 Access:R DESCR:DENC Status
#define DEN_IDFS1 0x0000060a //bits:8 Access:R/W DESCR:DENC Increment for Digital Frequency Synthesizer
#define DEN_IDFS2 0x0000060b //bits:8 Access:R/W DESCR:DENC Increment for Digital Frequency Synthesizer
#define DEN_IDFS3 0x0000060c //bits:8 Access:R/W DESCR:DENC Increment for Digital Frequency Synthesizer
#define DEN_PDFS1 0x0000060d //bits:8 Access:R/W DESCR:Static phase offset for digital frequency synthesizer
#define DEN_PDFS2 0x0000060e //bits:8 Access:R/W DESCR:Static phase offset for digital frequency synthesizer
#define DEN_WSS1 0x0000060f //bits:8 Access:R/W DESCR:WSS data registers
#define DEN_WSS2 0x00000610 //bits:8 Access:R/W DESCR:WSS data registers
#define DEN_DAC13 0x00000611 //bits:8 Access:R/W DESCR:DAC1 and DAC3 multiplying factors
#define DEN_DAC45 0x00000612 //bits:8 Access:R/W DESCR:DAC4 and DAC5 multiplying factors
#define DEN_DAC6C 0x00000613 //bits:8 Access:R/W DESCR:DAC6 and C multiplying factors
#define DEN_LJMP1 0x00000615 //bits:8 Access:R/W DESCR:Line jump
#define DEN_LJMP2 0x00000616 //bits:8 Access:R/W DESCR:Line jump
#define DEN_LJMP3 0x00000617 //bits:8 Access:R/W DESCR:Line jump
#define DEN_CID 0x00000618 //bits:8 Access:R DESCR:DENC identification number
#define DEN_VPS1 0x00000619 //bits:8 Access:R/W DESCR:VPS data registers
#define DEN_VPS2 0x0000061a //bits:8 Access:R/W DESCR:VPS data registers
#define DEN_VPS3 0x0000061b //bits:8 Access:R/W DESCR:VPS data registers
#define DEN_VPS4 0x0000061c //bits:8 Access:R/W DESCR:VPS data registers
#define DEN_VPS5 0x0000061d //bits:8 Access:R/W DESCR:VPS data registers
#define DEN_VPS6 0x0000061e //bits:8 Access:R/W DESCR:VPS data registers
#define DEN_CGMS1 0x0000061f //bits:4 Access:R/W DESCR:CGMS data registers
#define DEN_CGMS2 0x00000620 //bits:8 Access:R/W DESCR:CGMS data registers
#define DEN_CGMS3 0x00000621 //bits:8 Access:R/W DESCR:CGMS data registers
#define DEN_TTX1 0x00000622 //bits:8 Access:R/W DESCR:Teletext block definition
#define DEN_TTX2 0x00000623 //bits:8 Access:R/W DESCR:Teletext block definition
#define DEN_TTX3 0x00000624 //bits:8 Access:R/W DESCR:Teletext block definition
#define DEN_TTX4 0x00000625 //bits:8 Access:R/W DESCR:Teletext block definition
#define DEN_TTXM 0x00000626 //bits:8 Access:R/W DESCR:Teletext block mapping
#define DEN_CCF1 0x00000627 //bits:8 Access:R/W DESCR:Closed caption characters/extended data for field 1
#define DEN_CCF1B 0x00000628 //bits:8 Access:R/W DESCR:Closed caption characters/extended data for field 1
#define DEN_CCF2 0x00000629 //bits:8 Access:R/W DESCR:Closed caption characters/extended data for field 2
#define DEN_CCF2B 0x0000062a //bits:8 Access:R/W DESCR:Closed caption characters/extended data for field 2
#define DEN_CLF1 0x0000062b //bits:5 Access:R/W DESCR:Closed caption/extended data line insert for field 1
#define DEN_CLF2 0x0000062c //bits:5 Access:R/W DESCR:Closed caption/extended data line insert for field 2
#define DEN_REG_45 0x0000062d //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_46 0x0000062e //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_47 0x0000062f //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_48 0x00000630 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_49 0x00000631 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_50 0x00000632 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_51 0x00000633 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_52 0x00000634 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_53 0x00000635 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_54 0x00000636 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_55 0x00000637 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_56 0x00000638 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_57 0x00000639 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_58 0x0000063a //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_59 0x0000063b //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_60 0x0000063c //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_61 0x0000063d //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_62 0x0000063e //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_63 0x0000063f //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_64 0x00000640 //bits:3 Access:R/W DESCR:TTX_conf
#define DEN_REG_65 0x00000641 //bits:8 Access:R/W DESCR:DAC2MULT&TTXS
#define DEN_REG_66 0x00000642 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_67 0x00000643 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_68 0x00000644 //bits:0 Access:?? DESCR:RESERVED
#define DEN_REG_69 0x00000645 //bits:8 Access:R/W DESCR:Brightness
#define DEN_REG_70 0x00000646 //bits:8 Access:R/W DESCR:Contrast
#define DEN_REG_71 0x00000647 //bits:8 Access:R/W DESCR:Saturation
#define MPEG_CONTROL_7_0 0x00000e00 //bits:8 Access:R/W DESCR:MPEG Audio/Video buffer control register
#define MPEG_CONTROL_14_8 0x00000e01 //bits:8 Access:R/W DESCR:MPEG Audio/Video buffer control register
#define EMI_CONFIGDATA0BANK0 0x00002000 //bits:16 Access:R/W DESCR:EMI bank 0 configuration data register 0 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA1BANK0 0x00002004 //bits:16 Access:R/W DESCR:EMI bank 0 configuration data register 1 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA2BANK0 0x00002008 //bits:16 Access:R/W DESCR:EMI bank 0 configuration data register 2 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA3BANK0 0x0000200c //bits:16 Access:R/W DESCR:EMI bank 0 configuration data register 3 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA0BANK1 0x00002010 //bits:16 Access:R/W DESCR:EMI bank 1 configuration data register 0 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA1BANK1 0x00002014 //bits:16 Access:R/W DESCR:EMI bank 1 configuration data register 1 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA2BANK1 0x00002018 //bits:16 Access:R/W DESCR:EMI bank 1 configuration data register 2 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA3BANK1 0x0000201c //bits:16 Access:R/W DESCR:EMI bank 1 configuration data register 3 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA0BANK2 0x00002020 //bits:16 Access:R/W DESCR:EMI bank 2 configuration data register 0 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA1BANK2 0x00002024 //bits:16 Access:R/W DESCR:EMI bank 2 configuration data register 1 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA2BANK2 0x00002028 //bits:16 Access:R/W DESCR:EMI bank 2 configuration data register 2 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA3BANK2 0x0000202c //bits:16 Access:R/W DESCR:EMI bank 2 configuration data register 3 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA0BANK3 0x00002030 //bits:16 Access:R/W DESCR:EMI bank 3 configuration data register 0 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA1BANK3 0x00002034 //bits:16 Access:R/W DESCR:EMI bank 3 configuration data register 1 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA2BANK3 0x00002038 //bits:16 Access:R/W DESCR:EMI bank 3 configuration data register 2 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGDATA3BANK3 0x0000203c //bits:16 Access:R/W DESCR:EMI bank 3 configuration data register 3 SDRAM, DRAM and peripheral memory formats
#define EMI_CONFIGLOCKBANK0 0x00002040 //bits:1 Access:W DESCR:Write protection bit. When set, makes EMI_ConfigData 0-3 for Bank0 read only
#define EMI_CONFIGLOCKBANK0 0x00002044 //bits:1 Access:W DESCR:Write protection bit. When set, makes EMI_ConfigData 0-3 for Bank1 read only
#define EMI_CONFIGLOCKBANK0 0x00002048 //bits:1 Access:W DESCR:Write protection bit. When set, makes EMI_ConfigData 0-3 for Bank2 read only
#define EMI_CONFIGLOCKBANK0 0x0000204c //bits:1 Access:W DESCR:Write protection bit. When set, makes EMI_ConfigData 0-3 for Bank3 read only
#define EMI_CONFIGSTATUS 0x00002050 //bits:8 Access:R DESCR:Status information
#define EMI_SDRAMMODEREG0 0x00002058 //bits:7 Access:W DESCR:SDRAM Mode Register for either the case of one SDRAM bank or SDRAM in bank0, when two SDRAM banks.
#define EMI_SDRAMMODEREG1 0x0000205c //bits:7 Access:W DESCR:SDRAM Mode Register in the case
#define EMI_DRAMINITIALIZE 0x00002060 //bits:1 Access:W DESCR:Initialize any (S)DRAM in the system.
#define EMI_CONFIGPADLOGIC 0x00002070 //bits:14 Access:R/W DESCR:Padlogic configuration data register.
#define DCU 0x00003004 //bits:8 Access:R/W DESCR:Diagnostic Control Unit Register.
#define CAC_CACHECONTROL0 0x00004000 //bits:8 Access:R/W DESCR:Cacheability of 0xC0000000 to 0xC007FFFF
#define CAC_CACHECONTROL1 0x00004100 //bits:8 Access:R/W DESCR:Cacheability of 0xC0200000 to 0xC027FFFF
#define CAC_CACHECONTROL2 0x00004200 //bits:8 Access:R/W DESCR:Cacheability of 0x40000000 to 0x4007FFFF
#define CAC_CACHECONTROL3 0x00004300 //bits:4 Access:R/W DESCR:Cacheability of 0x40000000 to 0x7FFFFFFF
#define CAC_DCACHENOTSRAM 0x00004400 //bits:1 Access:W DESCR:Select data cache or extra SRAM
#define CAC_INVALIDATEDCACHE 0x00004500 //bits:1 Access:W DESCR:Invalidate the data cache
#define CAC_FLUSHDCACHE 0x00004600 //bits:1 Access:W DESCR:Flush the data cache
#define CAC_ENABLEICACHE 0x00004700 //bits:1 Access:W DESCR:Enable the instruction cache
#define CAC_INVALIDATEICACHE 0x00004800 //bits:1 Access:W DESCR:Invalidate the instruction cache
#define CAC_CACHESTATUS 0x00004900 //bits:7 Access:R DESCR:Cache status
#define CAC_CACHECONTROLLOCK 0x00004a00 //bits:1 Access:R/W DESCR:Lock the cache configuration
#define INC_HANDLERWPTR0 0x20000000 //bits:32 Access:R/W DESCR:Interrupt handler 0 work space pointer
#define INC_HANDLERWPTR1 0x20000004 //bits:32 Access:R/W DESCR:Interrupt handler 1 work space pointer
#define INC_HANDLERWPTR2 0x20000008 //bits:32 Access:R/W DESCR:Interrupt handler 2 work space pointer
#define INC_HANDLERWPTR3 0x2000000c //bits:32 Access:R/W DESCR:Interrupt handler 3 work space pointer
#define INC_HANDLERWPTR4 0x20000010 //bits:32 Access:R/W DESCR:Interrupt handler 4 work space pointer
#define INC_HANDLERWPTR5 0x20000014 //bits:32 Access:R/W DESCR:Interrupt handler 5 work space pointer
#define INC_HANDLERWPTR6 0x20000018 //bits:32 Access:R/W DESCR:Interrupt handler 6 work space pointer
#define INC_HANDLERWPTR7 0x2000001c //bits:32 Access:R/W DESCR:Interrupt handler 7 work space pointer
#define INC_TRIGGERMODE0 0x20000040 //bits:3 Access:R/W DESCR:Interrupt 0 trigger mode
#define INC_TRIGGERMODE1 0x20000044 //bits:3 Access:R/W DESCR:Interrupt 1 trigger mode
#define INC_TRIGGERMODE2 0x20000048 //bits:3 Access:R/W DESCR:Interrupt 2 trigger mode
#define INC_TRIGGERMODE3 0x2000004c //bits:3 Access:R/W DESCR:Interrupt trigger mode
#define INC_TRIGGERMODE4 0x20000050 //bits:3 Access:R/W DESCR:Interrupt 3 trigger mode
#define INC_TRIGGERMODE5 0x20000054 //bits:3 Access:R/W DESCR:Interrupt 4 trigger mode
#define INC_TRIGGERMODE6 0x20000058 //bits:3 Access:R/W DESCR:Interrupt 5 trigger mode
#define INC_TRIGGERMODE7 0x2000005c //bits:3 Access:R/W DESCR:Interrupt 6 trigger mode
#define INC_PENDING 0x20000080 //bits:8 Access:R/W DESCR:Interrupt pending
#define INC_SET_PENDING 0x20000084 //bits:8 Access:W DESCR:Set a bit of the Pending register
#define INC_CLEAR_PENDING 0x20000088 //bits:8 Access:W DESCR:Clear a bit of the Pending register
#define INC_MASK 0x200000c0 //bits:17 Access:R/W DESCR:Interrupt enable mask
#define INC_SET_MASK 0x200000c4 //bits:17 Access:W DESCR:Set a bit of the interrupt enable mask
#define INC_CLEAR_MASK 0x200000c8 //bits:17 Access:W DESCR:Clear a bit of the interrupt enable mask
#define INC_EXEC 0x20000100 //bits:8 Access:R/W DESCR:Interrupts executing
#define INC_SET_EXEC 0x20000104 //bits:8 Access:W DESCR:Set a bit of the Exec register
#define INC_CLEAR_EXEC 0x20000108 //bits:8 Access:W DESCR:Clear a bit of the Exec register
#define LPM_TIMER_31_0 0x20000400 //bits:32 Access:R/W DESCR:Low power timer least significant word
#define LPM_TIMER_32_63 0x20000404 //bits:32 Access:R/W DESCR:Low power timer most significant word
#define LPM_TIMERSTART 0x20000408 //bits:1 Access:W DESCR:Low power timer start
#define LPM_ALARM_31_0 0x20000410 //bits:32 Access:R/W DESCR:Low power alarm least significant word
#define LPM_ALARM_32_39 0x20000414 //bits:8 Access:R/W DESCR:Low power alarm most significant word
#define LPM_ALARMSTART 0x20000418 //bits:1 Access:W DESCR:Low power alarm start
#define LPM_SYSPLL 0x20000420 //bits:2 Access:R/W DESCR:System clock PLL
#define LPM_SYSRATIO 0x20000500 //bits:6 Access:R DESCR:System clock ratio
#define LPM_WDENABLE 0x20000510 //bits:1 Access:R/W DESCR:Watchdog enable
#define LPM_WDFLAG 0x20000514 //bits:1 Access:R DESCR:Watchdog flag
#define DESC_KEY0_EVEN_LSW 0x20002500 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 0 EVEN 31:0 (LSW)
#define DESC_KEY0_EVEN_MSW 0x20002504 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 0 EVEN 63:32 (MSW)
#define DESC_KEY0_ODD_LSW 0x20002508 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 0 ODD 31:0 (LSW)
#define DESC_KEY0_ODD_MSW 0x2000250c //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 0 ODD 63:32 (MSW)
#define DESC_KEY1_EVEN_LSW 0x20002510 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 1 EVEN 31:0 (LSW)
#define DESC_KEY1_EVEN_MSW 0x20002514 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 1 EVEN 63:32 (MSW)
#define DESC_KEY1_ODD_LSW 0x20002518 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 1 ODD 31:0 (LSW)
#define DESC_KEY1_ODD_MSW 0x2000251c //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 1 ODD 63:32 (MSW)
#define DESC_KEY2_EVEN_LSW 0x20002520 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 2 EVEN 31:0 (LSW)
#define DESC_KEY2_EVEN_MSW 0x20002524 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 2 EVEN 63:32 (MSW)
#define DESC_KEY2_ODD_LSW 0x20002528 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 2 ODD 31:0 (LSW)
#define DESC_KEY2_ODD_MSW 0x2000252c //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 2 ODD 63:32 (MSW)
#define DESC_KEY3_EVEN_LSW 0x20002530 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 3 EVEN 31:0 (LSW)
#define DESC_KEY3_EVEN_MSW 0x20002534 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 3 EVEN 63:32 (MSW)
#define DESC_KEY3_ODD_LSW 0x20002538 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 3 ODD 31:0 (LSW)
#define DESC_KEY3_ODD_MSW 0x2000253c //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 3 ODD 63:32 (MSW)
#define DESC_KEY4_EVEN_LSW 0x20002540 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 4 EVEN 31:0 (LSW)
#define DESC_KEY4_EVEN_MSW 0x20002544 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 4 EVEN 63:32 (MSW)
#define DESC_KEY4_ODD_LSW 0x20002548 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 4 ODD 31:0 (LSW)
#define DESC_KEY4_ODD_MSW 0x2000254c //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 4 ODD 63:32 (MSW)
#define DESC_KEY5_EVEN_LSW 0x20002550 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 5 EVEN 31:0 (LSW)
#define DESC_KEY5_EVEN_MSW 0x20002554 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 5 EVEN 63:32 (MSW)
#define DESC_KEY5_ODD_LSW 0x20002558 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 5 ODD 31:0 (LSW)
#define DESC_KEY5_ODD_MSW 0x2000255c //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 5 ODD 63:32 (MSW)
#define DESC_KEY6_EVEN_LSW 0x20002560 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 6 EVEN 31:0 (LSW)
#define DESC_KEY6_EVEN_MSW 0x20002564 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 6 EVEN 63:32 (MSW)
#define DESC_KEY6_ODD_LSW 0x20002568 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 6 ODD 31:0 (LSW)
#define DESC_KEY6_ODD_MSW 0x2000256c //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 6 ODD 63:32 (MSW)
#define DESC_KEY7_EVEN_LSW 0x20002570 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 7 EVEN 31:0 (LSW)
#define DESC_KEY7_EVEN_MSW 0x20002574 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 7 EVEN 63:32 (MSW)
#define DESC_KEY7_ODD_LSW 0x20002578 //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 7 ODD 31:0 (LSW)
#define DESC_KEY7_ODD_MSW 0x2000257c //bits:32 Access:R/W DESCR:DESCRAMBLER KEY 7 ODD 63:32 (MSW)
#define ASC_0_BAUDRATE 0x20003000 //bits:16 Access:R/W DESCR:ASC 0 Baud rate generator/reload
#define ASC_0_TXBUFFER 0x20003004 //bits:9 Access:W DESCR:ASC 0 Output buffer
#define ASC_0_RXBUFFER 0x20003008 //bits:9 Access:R DESCR:ASC 0 Input buffer
#define ASC_0_CONTROL 0x2000300c //bits:13 Access:R/W DESCR:ASC 0 Control register
#define ASC_0_INTENABLE 0x20003010 //bits:9 Access:R/W DESCR:ASC 0 Enable interrupts
#define ASC_0_STATUS 0x20003014 //bits:11 Access:R DESCR:ASC 0 Interrupt status
#define ASC_0_GUARDTIME 0x20003018 //bits:8 Access:R/W DESCR:ASC 0 Delay before transmitter empty flag
#define ASC_0_TIMEOUT 0x2000301c //bits:8 Access:R/W DESCR:ASC 0 Time out register
#define ASC_0_TXRESET 0x20003020 //bits:0 Access:W DESCR:ASC 0 Reset output FIFO
#define ASC_0_RXRESET 0x20003024 //bits:0 Access:W DESCR:ASC 0 Reset input FIFO
#define ASC_0_RETRIES 0x20003028 //bits:8 Access:R/W DESCR:ASC 0 number of retries on transmission
#define ASC_1_BAUDRATE 0x20004000 //bits:16 Access:R/W DESCR:ASC 1 Baud rate generator/reload
#define ASC_1_TXBUFFER 0x20004004 //bits:9 Access:W DESCR:ASC 1 Output buffer
#define ASC_1_RXBUFFER 0x20004008 //bits:9 Access:R DESCR:ASC 1 Input buffer
#define ASC_1_CONTROL 0x2000400c //bits:13 Access:R/W DESCR:ASC 1 Control register
#define ASC_1_INTENABLE 0x20004010 //bits:9 Access:R/W DESCR:ASC 1 Enable interrupts
#define ASC_1_STATUS 0x20004014 //bits:11 Access:R DESCR:ASC 1 Interrupt status
#define ASC_1_GUARDTIME 0x20004018 //bits:8 Access:R/W DESCR:ASC 1 Delay before transmitter empty flag
#define ASC_1_TIMEOUT 0x2000401c //bits:8 Access:R/W DESCR:ASC 1 Time out register
#define ASC_1_TXRESET 0x20004020 //bits:0 Access:W DESCR:ASC 1 Reset output FIFO
#define ASC_1_RXRESET 0x20004024 //bits:0 Access:W DESCR:ASC 1 Reset input FIFO
#define ASC_1_RETRIES 0x20004028 //bits:8 Access:R/W DESCR:ASC 1 number of retries on transmission
#define ASC_2_BAUDRATE 0x20005000 //bits:16 Access:R/W DESCR:ASC 2 Baud rate generator/reload
#define ASC_2_TXBUFFER 0x20005004 //bits:9 Access:W DESCR:ASC 2 Output buffer
#define ASC_2_RXBUFFER 0x20005008 //bits:9 Access:R DESCR:ASC 2 Input buffer
#define ASC_2_CONTROL 0x2000500c //bits:13 Access:R/W DESCR:ASC 2 Control register
#define ASC_2_INTENABLE 0x20005010 //bits:9 Access:R/W DESCR:ASC 2 Enable interrupts
#define ASC_2_STATUS 0x20005014 //bits:11 Access:R DESCR:ASC 2 Interrupt status
#define ASC_2_GUARDTIME 0x20005018 //bits:8 Access:R/W DESCR:ASC 2 Delay before transmitter empty flag
#define ASC_2_TIMEOUT 0x2000501c //bits:8 Access:R/W DESCR:ASC 2 Time out register
#define ASC_2_TXRESET 0x20005020 //bits:0 Access:W DESCR:ASC 2 Reset output FIFO
#define ASC_2_RXRESET 0x20005024 //bits:0 Access:W DESCR:ASC 2 Reset input FIFO
#define ASC_2_RETRIES 0x20005028 //bits:8 Access:R/W DESCR:ASC 2 number of retries on transmission
#define ASC_3_BAUDRATE 0x20006000 //bits:16 Access:R/W DESCR:ASC 3 Baud rate generator/reload
#define ASC_3_TXBUFFER 0x20006004 //bits:9 Access:W DESCR:ASC 3 Output buffer
#define ASC_3_RXBUFFER 0x20006008 //bits:9 Access:R DESCR:ASC 3 Input buffer
#define ASC_3_CONTROL 0x2000600c //bits:13 Access:R/W DESCR:ASC 3 Control register
#define ASC_3_INTENABLE 0x20006010 //bits:9 Access:R/W DESCR:ASC 3 Enable interrupts
#define ASC_3_STATUS 0x20006014 //bits:11 Access:R DESCR:ASC 3 Interrupt status
#define ASC_3_GUARDTIME 0x20006018 //bits:8 Access:R/W DESCR:ASC 3 Delay before transmitter empty flag
#define ASC_3_TIMEOUT 0x2000601c //bits:8 Access:R/W DESCR:ASC 3 Time out register
#define ASC_3_TXRESET 0x20006020 //bits:0 Access:W DESCR:ASC 3 Reset output FIFO
#define ASC_3_RXRESET 0x20006024 //bits:0 Access:W DESCR:ASC 3 Reset input FIFO
#define ASC_3_RETRIES 0x20006028 //bits:8 Access:R/W DESCR:ASC 3 number of retries on transmission
#define SCI_SC0CLKVAL 0x20007000 //bits:5 Access:W DESCR:SmartCard 0 clock
#define SCI_SC0CLKCON 0x20007004 //bits:2 Access:W DESCR:SmartCard 0 clock control
#define SCI_SC1CLKVAL 0x20008000 //bits:5 Access:W DESCR:SmartCard 1 clock
#define SCI_SC1CLKCON 0x20008004 //bits:2 Access:W DESCR:SmartCard 1 clock control
#define SSC_0_BRG 0x20009000 //bits:10 Access:R/W DESCR:SSC 0 baud rate generation
#define SSC_0_TBuf 0x20009004 //bits:16 Access:W DESCR:SSC 0 transmit buffer
#define SSC_0_RBuf 0x20009008 //bits:16 Access:R DESCR:SSC 0 receive buffer
#define SSC_0_Con 0x2000900c //bits:11 Access:R/W DESCR:SSC 0 control
#define SSC_0_IEn 0x20009010 //bits:9 Access:R/W DESCR:SSC 0 interrupt enable
#define SSC_0_Stat 0x20009014 //bits:10 Access:R DESCR:SSC 0 status
#define SSC_0_I2C 0x20009018 //bits:5 Access:R/W DESCR:SSC 0 I2C control
#define SSC_0_SlAd 0x2000901c //bits:16 Access:W DESCR:SSC 0 slave address
#define SSC_1_BRG 0x2000a000 //bits:10 Access:R/W DESCR:SSC 1 baud rate generation
#define SSC_1_TBuf 0x2000a004 //bits:16 Access:W DESCR:SSC 1 transmit buffer
#define SSC_1_RBuf 0x2000a008 //bits:16 Access:R DESCR:SSC 1 receive buffer
#define SSC_1_Con 0x2000a00c //bits:11 Access:R/W DESCR:SSC 1 control
#define SSC_1_IEn 0x2000a010 //bits:9 Access:R/W DESCR:SSC 1 interrupt enable
#define SSC_1_Stat 0x2000a014 //bits:10 Access:R DESCR:SSC 1 status
#define SSC_1_I2C 0x2000a018 //bits:5 Access:R/W DESCR:SSC 1 I2C control
#define SSC_1_SlAd 0x2000a01c //bits:16 Access:W DESCR:SSC 1 slave address
#define PIO_P5OUT 0x2000a100 //bits:8 Access:R/W DESCR:PIO 5 output
#define PIO_SET_P5OUT 0x2000a104 //bits:8 Access:W DESCR:Set bits of P5Out
#define PIO_CLEAR_P5OUT 0x2000a108 //bits:8 Access:W DESCR:Clear bits of P5Out
#define PIO_P5IN 0x2000a110 //bits:8 Access:R DESCR:PIO 5 input
#define PIO_P5C0 0x2000a120 //bits:8 Access:R/W DESCR:PIO 5 configuration 0
#define PIO_SET_P5C0 0x2000a124 //bits:8 Access:W DESCR:Set bits of P5C0
#define PIO_CLEAR_P5C0 0x2000a128 //bits:8 Access:W DESCR:Clear bits of P5C0
#define PIO_P5C1 0x2000a130 //bits:8 Access:R/W DESCR:PIO 5 configuration 1
#define PIO_SET_P5C1 0x2000a134 //bits:8 Access:W DESCR:Set bits of P5C1
#define PIO_CLEAR_P5C1 0x2000a138 //bits:8 Access:W DESCR:Clear bits of P5C1
#define PIO_P5C2 0x2000a140 //bits:8 Access:R/W DESCR:PIO 5 configuration 2
#define PIO_SET_P5C2 0x2000a144 //bits:8 Access:W DESCR:Set bits of P5C2
#define PIO_CLEAR_P5C2 0x2000a148 //bits:8 Access:W DESCR:Clear bits of P5C2
#define PIO_P5COMP 0x2000a150 //bits:8 Access:R/W DESCR:PIO 5 input comparison
#define PIO_SET_P5COMP 0x2000a154 //bits:8 Access:W DESCR:Set bits of P5Comp
#define PIO_CLEAR_P5COMP 0x2000a158 //bits:8 Access:W DESCR:Clear bits of P5Comp.
#define PIO_P5MASK 0x2000a160 //bits:8 Access:R/W DESCR:PIO 5 input comparison mask
#define PIO_SET_P5MASK 0x2000a164 //bits:8 Access:W DESCR:Set bits of P5Mask
#define PIO_CLEAR_P5MASK 0x2000a168 //bits:8 Access:W DESCR:Clear bits of P5Mask
#define IRB_TX_PRE_SCALER_IR 0x2000a200 //bits:8 Access:W/R DESCR:Clock pre-scaler selection
#define IRB_TX_SUB_CARRIER_IR 0x2000a204 //bits:16 Access:W/R DESCR:sub-carrier freq. programming
#define IRB_TX_SYM_TIME_IR1 0x2000a208 //bits:16 Access:W DESCR:symbol time programming
#define IRB_TX_ON_TIME_IR1 0x2000a20c //bits:16 Access:W DESCR:symbol on time programming
#define IRB_TX_INT_EN_IR 0x2000a210 //bits:3 Access:W/R DESCR:Transmit Interrupt enable register
#define IRB_TX_INT_STATUS_IR 0x2000a214 //bits:4 Access:R DESCR:Transmit Interrupt status register
#define IRB_TX_EN_IR 0x2000a218 //bits:1 Access:W/R DESCR:RC transmit enable register
#define IRB_TX_CLR_UNDERRUN_IR 0x2000a21c //bits:1 Access:W DESCR:Clears the underrun status
#define IRB_RX_ON_TIME_IR1 0x2000a240 //bits:16 Access:R DESCR:Received pulse time capture RC
#define IRB_RX_SYM_TIME_IR1 0x2000a244 //bits:16 Access:R DESCR:Received symbol time capture
#define IRB_RX_INT_EN_IR 0x2000a248 //bits:4 Access:W/R DESCR:Receive Interrupt enable register
#define IRB_RX_INT_STATUS_IR 0x2000a24c //bits:5 Access:R DESCR:Receive Interrupt status register
#define IRB_RX_EN_IR 0x2000a250 //bits:1 Access:W/R DESCR:RC receive enable register
#define IRB_RX_MAX_SYM_TIME_IR 0x2000a254 //bits:16 Access:W/R DESCR:Maximum RC symbol time register
#define IRB_RX_CLR_OVERRUN_IR 0x2000a258 //bits:1 Access:W DESCR:Clears the overrun status
#define IRB_RX_NOISE_SUPPRESS_WIDTH_IR 0x2000a25c //bits:8 Access:W/R DESCR:Reserved
#define IRB_RC_IRDA_CONTROL 0x2000a260 //bits:1 Access:W/R DESCR:Reserved
#define IRB_RX_SAMPLING_RATE_COMMON 0x2000a264 //bits:4 Access:W/R DESCR:Sampling frequency division for UHF and IR frequencies.
#define IRB_RX_ON_TIME_UHF1 0x2000a280 //bits:16 Access:R DESCR:Received pulse time capture
#define IRB_RX_SYM_TIME_UHF1 0x2000a284 //bits:16 Access:R DESCR:Received symbol time capture
#define IRB_RX_INT_EN_UHF 0x2000a288 //bits:4 Access:W/R DESCR:Receive Interrupt enable register
#define IRB_RX_INT_STATUS_UHF 0x2000a28c //bits:5 Access:R DESCR:Receive Interrupt status register
#define IRB_RX_EN_UHF 0x2000a290 //bits:1 Access:W/R DESCR:RC receive enable register
#define IRB_RX_MAX_SYM_TIME_UHF 0x2000a294 //bits:16 Access:W/R DESCR:Maximum RC symbol time register
#define IRB_RX_CLR_OVERRUN_UHF 0x2000a298 //bits:1 Access:W DESCR:Clears the overrun status
#define IRB_RX_NOISE_SUPPRESS_WIDTH_UHF 0x2000a29c //bits:8 Access:W/R DESCR:Noise suppression width
#define TTXT_DMAADDRESS 0x2000a300 //bits:32 Access:R/W DESCR:Teletext DMA address
#define TTXT_DMACOUNT 0x2000a304 //bits:11 Access:R/W DESCR:Teletext DMA count
#define TTXT_OUTDELAY 0x2000a308 //bits:9 Access:R/W DESCR:Teletext output delay
#define TTXT_INTSTATUS 0x2000a318 //bits:3 Access:R DESCR:Teletext interrupt status
#define TTXT_INTENABLE 0x2000a31c //bits:3 Access:R/W DESCR:Teletext interrupt enable
#define TTXT_ACKODDEVEN 0x2000a320 //bits:1 Access:W DESCR:Teletext acknowledge odd or even
#define TTXT_ABORT 0x2000a324 //bits:1 Access:W DESCR:Teletext abort
#define PWM_0VAL 0x2000b000 //bits:9 Access:R/W DESCR:PWM 0 pulse width
#define PWM_1VAL 0x2000b004 //bits:9 Access:R/W DESCR:PWM 1 pulse width
#define PWM_2VAL 0x2000b008 //bits:9 Access:R/W DESCR:PWM 2 pulse width
#define PWM_3VAL 0x2000b00c //bits:9 Access:R/W DESCR:PWM 3 pulse width
#define PWM_0CAPTUREVAL 0x2000b010 //bits:32 Access:R DESCR:PWM 0 capture value
#define PWM_1CAPTUREVAL 0x2000b014 //bits:32 Access:R DESCR:PWM 1 capture value
#define PWM_2CAPTUREVAL 0x2000b018 //bits:32 Access:R DESCR:PWM 2 capture value
#define PWM_3CAPTUREVAL 0x2000b01c //bits:32 Access:R DESCR:PWM 3 capture value
#define PWM_0COMPAREVAL 0x2000b020 //bits:32 Access:R/W DESCR:PWM 0 compare value
#define PWM_1COMPAREVAL 0x2000b024 //bits:32 Access:R/W DESCR:PWM 1 compare value
#define PWM_2COMPAREVAL 0x2000b028 //bits:32 Access:R/W DESCR:PWM 2 compare value
#define PWM_3COMPAREVAL 0x2000b02c //bits:32 Access:R/W DESCR:PWM 3 compare value
#define PWM_0CAPTUREEDGE 0x2000b030 //bits:2 Access:R/W DESCR:PWM 0 capture event definition
#define PWM_1CAPTUREEDGE 0x2000b034 //bits:2 Access:R/W DESCR:PWM 1 capture event definition
#define PWM_2CAPTUREEDGE 0x2000b038 //bits:2 Access:R/W DESCR:PWM 2 capture event definition
#define PWM_3CAPTUREEDGE 0x2000b03c //bits:2 Access:R/W DESCR:PWM 3 capture event definition
#define PWM_0COMPAREOUTVAL 0x2000b040 //bits:1 Access:R/W DESCR:PWM 0 compare output value
#define PWM_CONTROL 0x2000b050 //bits:11 Access:R/W DESCR:PWM control register
#define PWM_INTENABLE 0x2000b054 //bits:9 Access:R/W DESCR:PWM interrupt enable
#define PWM_INTSTATUS 0x2000b058 //bits:9 Access:R DESCR:PWM interrupt status
#define PWM_INTACK 0x2000b05c //bits:9 Access:W DESCR:PWM interrupt acknowledge
#define PWM_COUNT 0x2000b060 //bits:8 Access:R/W DESCR:PWM output counter
#define PIO_P0OUT 0x2000c000 //bits:8 Access:R/W DESCR:PIO 0 output
#define PIO_SET_P0OUT 0x2000c004 //bits:8 Access:W DESCR:Set bits of P0Out
#define PIO_CLEAR_P0OUT 0x2000c008 //bits:8 Access:W DESCR:Clear bits of P0Out
#define PIO_P0IN 0x2000c010 //bits:8 Access:R DESCR:PIO 0 input
#define PIO_P0C0 0x2000c020 //bits:8 Access:R/W DESCR:PIO 0 configuration 0
#define PIO_SET_P0C0 0x2000c024 //bits:8 Access:W DESCR:Set bits of P0C0
#define PIO_CLEAR_P0C0 0x2000c028 //bits:8 Access:W DESCR:Clear bits of P0C0
#define PIO_P0C1 0x2000c030 //bits:8 Access:R/W DESCR:PIO 0 configuration 1
#define PIO_SET_P0C1 0x2000c034 //bits:8 Access:W DESCR:Set bits of P0C1
#define PIO_CLEAR_P0C1 0x2000c038 //bits:8 Access:W DESCR:Clear bits of P0C1
#define PIO_P0C2 0x2000c040 //bits:8 Access:R/W DESCR:PIO 0 configuration 2
#define PIO_SET_P0C2 0x2000c044 //bits:8 Access:W DESCR:Set bits of P0C2
#define PIO_CLEAR_P0C2 0x2000c048 //bits:8 Access:W DESCR:Clear bits of P0C2
#define PIO_P0COMP 0x2000c050 //bits:8 Access:R/W DESCR:PIO 0 input comparison
#define PIO_SET_P0COMP 0x2000c054 //bits:8 Access:W DESCR:Set bits of P0Comp
#define PIO_CLEAR_P0COMP 0x2000c058 //bits:8 Access:W DESCR:Clear bits of P0Comp.
#define PIO_P0MASK 0x2000c060 //bits:8 Access:R/W DESCR:PIO 0 input comparison mask
#define PIO_SET_P0MASK 0x2000c064 //bits:8 Access:W DESCR:Set bits of P0Mask
#define PIO_CLEAR_P0MASK 0x2000c068 //bits:8 Access:W DESCR:Clear bits of P0Mask
#define PIO_P1OUT 0x2000d000 //bits:8 Access:R/W DESCR:PIO 1 output
#define PIO_SET_P1OUT 0x2000d004 //bits:8 Access:W DESCR:Set bits of P1Out
#define PIO_CLEAR_P1OUT 0x2000d008 //bits:8 Access:W DESCR:Clear bits of P1Out
#define PIO_P1IN 0x2000d010 //bits:8 Access:R DESCR:PIO 1 input
#define PIO_P1C0 0x2000d020 //bits:8 Access:R/W DESCR:PIO 1 configuration 0
#define PIO_SET_P1C0 0x2000d024 //bits:8 Access:W DESCR:Set bits of P1C0
#define PIO_CLEAR_P1C0 0x2000d028 //bits:8 Access:W DESCR:Clear bits of P1C0
#define PIO_P1C1 0x2000d030 //bits:8 Access:R/W DESCR:PIO 1 configuration 1
#define PIO_SET_P1C1 0x2000d034 //bits:8 Access:W DESCR:Set bits of P1C1
#define PIO_CLEAR_P1C1 0x2000d038 //bits:8 Access:W DESCR:Clear bits of P1C1
#define PIO_P1C2 0x2000d040 //bits:8 Access:R/W DESCR:PIO 1 configuration 2
#define PIO_SET_P1C2 0x2000d044 //bits:8 Access:W DESCR:Set bits of P1C2
#define PIO_CLEAR_P1C2 0x2000d048 //bits:8 Access:W DESCR:Clear bits of P1C2
#define PIO_P1COMP 0x2000d050 //bits:8 Access:R/W DESCR:PIO 1 input comparison
#define PIO_SET_P1COMP 0x2000d054 //bits:8 Access:W DESCR:Set bits of P1Comp
#define PIO_CLEAR_P1COMP 0x2000d058 //bits:8 Access:W DESCR:Clear bits of P1Comp.
#define PIO_P1MASK 0x2000d060 //bits:8 Access:R/W DESCR:PIO 1 input comparison mask
#define PIO_SET_P1MASK 0x2000d064 //bits:8 Access:W DESCR:Set bits of P1Mask
#define PIO_CLEAR_P1MASK 0x2000d068 //bits:8 Access:W DESCR:Clear bits of P1Mask
#define PIO_P2OUT 0x2000e000 //bits:8 Access:R/W DESCR:PIO 2 output
#define PIO_SET_P2OUT 0x2000e004 //bits:8 Access:W DESCR:Set bits of P2Out
#define PIO_CLEAR_P2OUT 0x2000e008 //bits:8 Access:W DESCR:Clear bits of P2Out
#define PIO_P2IN 0x2000e010 //bits:8 Access:R DESCR:PIO 2 input
#define PIO_P2C0 0x2000e020 //bits:8 Access:R/W DESCR:PIO 2 configuration 0
#define PIO_SET_P2C0 0x2000e024 //bits:8 Access:W DESCR:Set bits of P2C0
#define PIO_CLEAR_P2C0 0x2000e028 //bits:8 Access:W DESCR:Clear bits of P2C0
#define PIO_P2C1 0x2000e030 //bits:8 Access:R/W DESCR:PIO 2 configuration 1
#define PIO_SET_P2C1 0x2000e034 //bits:8 Access:W DESCR:Set bits of P2C1
#define PIO_CLEAR_P2C1 0x2000e038 //bits:8 Access:W DESCR:Clear bits of P2C1
#define PIO_P2C2 0x2000e040 //bits:8 Access:R/W DESCR:PIO 2 configuration 2
#define PIO_SET_P2C2 0x2000e044 //bits:8 Access:W DESCR:Set bits of P2C2
#define PIO_CLEAR_P2C2 0x2000e048 //bits:8 Access:W DESCR:Clear bits of P2C2
#define PIO_P2COMP 0x2000e050 //bits:8 Access:R/W DESCR:PIO 2 input comparison
#define PIO_SET_P2COMP 0x2000e054 //bits:8 Access:W DESCR:Set bits of P2Comp
#define PIO_CLEAR_P2COMP 0x2000e058 //bits:8 Access:W DESCR:Clear bits of P2Comp.
#define PIO_P2MASK 0x2000e060 //bits:8 Access:R/W DESCR:PIO 2 input comparison mask
#define PIO_SET_P2MASK 0x2000e064 //bits:8 Access:W DESCR:Set bits of P2Mask
#define PIO_CLEAR_P2MASK 0x2000e068 //bits:8 Access:W DESCR:Clear bits of P2Mask
#define PIO_P3OUT 0x2000f000 //bits:8 Access:R/W DESCR:PIO 3 output
#define PIO_SET_P3OUT 0x2000f004 //bits:8 Access:W DESCR:Set bits of P3Out
#define PIO_CLEAR_P3OUT 0x2000f008 //bits:8 Access:W DESCR:Clear bits of P3Out
#define PIO_P3IN 0x2000f010 //bits:8 Access:R DESCR:PIO 3 input
#define PIO_P3C0 0x2000f020 //bits:8 Access:R/W DESCR:PIO 3 configuration 0
#define PIO_SET_P3C0 0x2000f024 //bits:8 Access:W DESCR:Set bits of P3C0
#define PIO_CLEAR_P3C0 0x2000f028 //bits:8 Access:W DESCR:Clear bits of P3C0
#define PIO_P3C1 0x2000f030 //bits:8 Access:R/W DESCR:PIO 3 configuration 1
#define PIO_SET_P3C1 0x2000f034 //bits:8 Access:W DESCR:Set bits of P3C1
#define PIO_CLEAR_P3C1 0x2000f038 //bits:8 Access:W DESCR:Clear bits of P3C1
#define PIO_P3C2 0x2000f040 //bits:8 Access:R/W DESCR:PIO 3 configuration 2
#define PIO_SET_P3C2 0x2000f044 //bits:8 Access:W DESCR:Set bits of P3C2
#define PIO_CLEAR_P3C2 0x2000f048 //bits:8 Access:W DESCR:Clear bits of P3C2
#define PIO_P3COMP 0x2000f050 //bits:8 Access:R/W DESCR:PIO 3 input comparison
#define PIO_SET_P3COMP 0x2000f054 //bits:8 Access:W DESCR:Set bits of P3Comp
#define PIO_CLEAR_P3COMP 0x2000f058 //bits:8 Access:W DESCR:Clear bits of P3Comp.
#define PIO_P3MASK 0x2000f060 //bits:8 Access:R/W DESCR:PIO 3 input comparison mask
#define PIO_SET_P3MASK 0x2000f064 //bits:8 Access:W DESCR:Set bits of P3Mask
#define PIO_CLEAR_P3MASK 0x2000f068 //bits:8 Access:W DESCR:Clear bits of P3Mask
#define PIO_P4OUT 0x20010000 //bits:8 Access:R/W DESCR:PIO 4 output
#define PIO_SET_P4OUT 0x20010004 //bits:8 Access:W DESCR:Set bits of P4Out
#define PIO_CLEAR_P4OUT 0x20010008 //bits:8 Access:W DESCR:Clear bits of P4Out
#define PIO_P4IN 0x20010010 //bits:8 Access:R DESCR:PIO 4 input
#define PIO_P4C0 0x20010020 //bits:8 Access:R/W DESCR:PIO 4 configuration 0
#define PIO_SET_P4C0 0x20010024 //bits:8 Access:W DESCR:Set bits of P4C0
#define PIO_CLEAR_P4C0 0x20010028 //bits:8 Access:W DESCR:Clear bits of P4C0
#define PIO_P4C1 0x20010030 //bits:8 Access:R/W DESCR:PIO 4 configuration 1
#define PIO_SET_P4C1 0x20010034 //bits:8 Access:W DESCR:Set bits of P4C1
#define PIO_CLEAR_P4C1 0x20010038 //bits:8 Access:W DESCR:Clear bits of P4C1
#define PIO_P4C2 0x20010040 //bits:8 Access:R/W DESCR:PIO 4 configuration 2
#define PIO_SET_P4C2 0x20010044 //bits:8 Access:W DESCR:Set bits of P4C2
#define PIO_CLEAR_P4C2 0x20010048 //bits:8 Access:W DESCR:Clear bits of P4C2
#define PIO_P4COMP 0x20010050 //bits:8 Access:R/W DESCR:PIO 4 input comparison
#define PIO_SET_P4COMP 0x20010054 //bits:8 Access:W DESCR:Set bits of P4Comp
#define PIO_CLEAR_P4COMP 0x20010058 //bits:8 Access:W DESCR:Clear bits of P4Comp.
#define PIO_P4MASK 0x20010060 //bits:8 Access:R/W DESCR:PIO 4 input comparison mask
#define PIO_SET_P4MASK 0x20010064 //bits:8 Access:W DESCR:Set bits of P4Mask
#define PIO_CLEAR_P4MASK 0x20010068 //bits:8 Access:W DESCR:Clear bits of P4Mask
#define INC_INT0PRIORITY 0x20011000 //bits:3 Access:R/W DESCR:Internal interrupt 0 priority
#define INC_INT1PRIORITY 0x20011004 //bits:3 Access:R/W DESCR:Internal interrupt 1 priority
#define INC_INT2PRIORITY 0x20011008 //bits:3 Access:R/W DESCR:Internal interrupt 2 priority
#define INC_INT3PRIORITY 0x2001100c //bits:3 Access:R/W DESCR:Internal interrupt 3 priority
#define INC_INT4PRIORITY 0x20011010 //bits:3 Access:R/W DESCR:Internal interrupt 4 priority
#define INC_INT5PRIORITY 0x20011014 //bits:3 Access:R/W DESCR:Internal interrupt 5 priority
#define INC_INT6PRIORITY 0x20011018 //bits:3 Access:R/W DESCR:Internal interrupt 6 priority
#define INC_INT7PRIORITY 0x2001101c //bits:3 Access:R/W DESCR:Internal interrupt 7 priority
#define INC_INT8PRIORITY 0x20011020 //bits:3 Access:R/W DESCR:Internal interrupt 8 priority
#define INC_INT9PRIORITY 0x20011024 //bits:3 Access:R/W DESCR:Internal interrupt 9 priority
#define INC_INT10PRIORITY 0x20011028 //bits:3 Access:R/W DESCR:Internal interrupt 10 priority
#define INC_INT11PRIORITY 0x2001102c //bits:3 Access:R/W DESCR:Internal interrupt 11 priority
#define INC_INT12PRIORITY 0x20011030 //bits:3 Access:R/W DESCR:Internal interrupt 12 priority
#define INC_INT13PRIORITY 0x20011034 //bits:3 Access:R/W DESCR:Internal interrupt 13 priority
#define INC_INT14PRIORITY 0x20011038 //bits:3 Access:R/W DESCR:Internal interrupt 14 priority
#define INC_INT15PRIORITY 0x2001103c //bits:3 Access:R/W DESCR:Internal interrupt 15 priority
#define INC_INT16PRIORITY 0x20011040 //bits:3 Access: R/W DESCR:Internal interrupt 16 priority
#define INC_INT17PRIORITY 0x20011044 //bits:3 Access: R/W DESCR:Internal interrupt 17 priority
#define INC_INT18PRIORITY 0x20011048 //bits:3 Access: R/W DESCR:Internal interrupt 18 priority
#define INC_INT19PRIORITY 0x2001104c //bits:3 Access: R/W DESCR:Internal interrupt 19 priority
#define INC_INT20PRIORITY 0x20011050 //bits:3 Access: R/W DESCR:Internal interrupt 20 priority (reserved)
#define INC_INT21PRIORITY 0x20011054 //bits:3 Access: R/W DESCR:Internal interrupt 21 priority (reserved)
#define INC_INT22PRIORITY 0x20011058 //bits:3 Access: R/W DESCR:Internal interrupt 22 priority (reserved)
#define INC_INT23PRIORITY 0x2001105c //bits:3 Access: R/W DESCR:Internal interrupt 23 priority (reserved)
#define INC_INT24PRIORITY 0x20011060 //bits:3 Access: R/W DESCR:External interrupt 0 priority
#define INC_INT25PRIORITY 0x20011064 //bits:3 Access: R/W DESCR:External interrupt 1 priority
#define INC_INT26PRIORITY 0x20011068 //bits:3 Access: R/W DESCR:External interrupt 2 priority
#define INC_INT27PRIORITY 0x2001106c //bits:3 Access: R/W DESCR:External interrupt 3 priority
#define INC_INT28PRIORITY 0x20011070 //bits:3 Access: R/W DESCR:External interrupt 4 priority
#define INC_INT29PRIORITY 0x20011074 //bits:3 Access: R/W DESCR:External interrupt 5 priority
#define INC_INT30PRIORITY 0x20011078 //bits:3 Access:R/W DESCR:External interrupt 6 priority
#define INC_INPUTINTERRUPTS 0x2001107c //bits:23 Access:R DESCR:Input interrupt status
#define INC_SRC0_TRIGGERMODE 0x200110bc //bits:3 Access:R/W DESCR:Interrupt source 0 trigger mode
#define INC_SRC1_TRIGGERMODE 0x200110c0 //bits:3 Access:R/W DESCR:Interrupt source 1 trigger mode
#define INC_SRC2_TRIGGERMODE 0x200110c4 //bits:3 Access:R/W DESCR:Interrupt source 2 trigger mode
#define INC_SRC3_TRIGGERMODE 0x200110c8 //bits:3 Access:R/W DESCR:Interrupt source 3 trigger mode
#define INC_SRC4_TRIGGERMODE 0x200110cc //bits:3 Access:R/W DESCR:Interrupt source 4 trigger mode
#define INC_SRC5_TRIGGERMODE 0x200110d0 //bits:3 Access:R/W DESCR:Interrupt source 5 trigger mode
#define INC_SRC6_TRIGGERMODE 0x200110d4 //bits:3 Access:R/W DESCR:Interrupt source 6 trigger mode
#define INC_SRC7_TRIGGERMODE 0x200110d8 //bits:3 Access:R/W DESCR:Interrupt source 7 trigger mode
#define INC_SRC8_TRIGGERMODE 0x200110dc //bits:3 Access:R/W DESCR:Interrupt source 8 trigger mode
#define INC_SRC9_TRIGGERMODE 0x200110e0 //bits:3 Access:R/W DESCR:Interrupt source 9 trigger mode
#define INC_SRC10_TRIGGERMODE 0x200110e4 //bits:3 Access:R/W DESCR:Interrupt source 10 trigger mode
#define INC_SRC11_TRIGGERMODE 0x200110e8 //bits:3 Access:R/W DESCR:Interrupt source 11 trigger mode
#define INC_SRC12_TRIGGERMODE 0x200110ec //bits:3 Access:R/W DESCR:Interrupt source 12 trigger mode
#define INC_SRC13_TRIGGERMODE 0x200110f0 //bits:3 Access:R/W DESCR:Interrupt source 13 trigger mode
#define INC_SRC14_TRIGGERMODE 0x200110f4 //bits:3 Access:R/W DESCR:Interrupt source 14 trigger mode
#define INC_SRC15_TRIGGERMODE 0x200110f8 //bits:3 Access:R/W DESCR:Interrupt source 15 trigger mode
#define INC_SRC16_TRIGGERMODE 0x200110fc //bits:3 Access:R/W DESCR:Interrupt source 16 trigger mode
#define INC_SRC17_TRIGGERMODE 0x20011100 //bits:3 Access:R/W DESCR:Interrupt source 17 trigger mode
#define INC_SRC18_TRIGGERMODE 0x20011104 //bits:3 Access:R/W DESCR:Interrupt source 18 trigger mode
#define INC_SRC19_TRIGGERMODE 0x20011108 //bits:3 Access:R/W DESCR:Interrupt source 19 trigger mode
#define INC_SRC20_TRIGGERMODE 0x2001110c //bits:3 Access:R/W DESCR:Interrupt source 20 trigger mode (reserved)
#define INC_SRC21_TRIGGERMODE 0x20011110 //bits:3 Access:R/W DESCR:Interrupt source 21 trigger mode (reserved)
#define INC_SRC22_TRIGGERMODE 0x20011114 //bits:3 Access:R/W DESCR:Interrupt source 22 trigger mode (reserved)
#define INC_SRC23_TRIGGERMODE 0x20011118 //bits:3 Access:R/W DESCR:Interrupt source 23 trigger mode (reserved)
#define INC_SRC24_TRIGGERMODE 0x2001111c //bits:3 Access:R/W DESCR:External interrupt source 0 trigger mode
#define INC_SRC25_TRIGGERMODE 0x20011120 //bits:3 Access:R/W DESCR:External interrupt source 1 trigger mode
#define INC_SRC26_TRIGGERMODE 0x20011124 //bits:3 Access:R/W DESCR:External interrupt source 2 trigger mode
#define INC_SRC27_TRIGGERMODE 0x20011128 //bits:3 Access:R/W DESCR:External interrupt source 3 trigger mode
#define INC_SRC28_TRIGGERMODE 0x2001112c //bits:3 Access:R/W DESCR:External interrupt source 4 trigger mode
#define INC_SRC29_TRIGGERMODE 0x20011130 //bits:3 Access:R/W DESCR:External interrupt source 5 trigger mode
#define INC_SRC30_TRIGGERMODE 0x20011134 //bits:3 Access:R/W DESCR:External interrupt source 6 trigger mode
#define INC_SRC_CLEAR_MASK 0x200111b4 //bits:31 Access:W DESCR:Clear interrupt-source enable register
#define INC_SRC_SET_MASK 0x200111b8 //bits:31 Access:W DESCR:Set interrupt-source enable mask
#define INC_SRC_MASK 0x200111bc //bits:31 Access:R/W DESCR:Interrupt-source enable mask
#define INC_SELNOTINV 0x200111c8 //bits:3 Access:R/W DESCR:External interrupt pin is set to active high or active low
#define INC_EN_INT 0x200111cc //bits:3 Access:R/W DESCR:Enable external interrupt to wake-up the low-power controller
#define INC_SRC_STATUS 0x200111dc //bits:31 Access:R DESCR:Gives the latched status of an interrupt source
#define INC_SRC_CLEAR 0x200111ec //bits:31 Access:R DESCR:Clears the INC_SRC_STATUS register
#define MPEGDMA0_BURSTSIZE 0x20024000 //bits:5 Access:W DESCR:The number of bytes to be transferred in one burst
#define MPEGDMA0_HOLDOFF 0x20024004 //bits:5 Access:W DESCR:Holdoff for MPEG decoder: range 0 to 31, where 0=0 delay cycles
#define MPEGDMA0_ABORT 0x20024008 //bits:1 Access:W DESCR:Abort all operation
#define MPEGDMA0_WHICHDEC 0x2002400c //bits:2 Access:W DESCR:DMA destination pointer
#define MPEGDMA0_STATUS 0x20024010 //bits:2 Access:R DESCR:Interrupt status register
#define MPEGDMA0_INTACK 0x20024014 //bits:1 Access:W DESCR:Interrupt acknowledge register
#define MPEGDMA0_SRCADD 0x20024018 //bits:32 Access:W DESCR:DMA source pointer
#define MPEGDMA0_CNTRL 0x2002401c //bits:2 Access:R/W DESCR:Interrupt control register
#define MPEGDMA0_BLSIZE 0x20024020 //bits:16 Access:W DESCR:Data block dimension to be transferred
#define MPEGDMA1_BURSTSIZE 0x20025000 //bits:5 Access:W DESCR:The number of bytes to be transferred in one burst
#define MPEGDMA1_HOLDOFF 0x20025004 //bits:5 Access:W DESCR:Holdoff for MPEG decoder: range 0 to 31, where 0=0 delay cycles
#define MPEGDMA1_ABORT 0x20025008 //bits:1 Access:W DESCR:Abort all operation
#define MPEGDMA1_WHICHDEC 0x2002500c //bits:2 Access:W DESCR:DMA destination pointer
#define MPEGDMA1_STATUS 0x20025010 //bits:2 Access:R DESCR:Interrupt status register
#define MPEGDMA1_INTACK 0x20025014 //bits:1 Access:W DESCR:Interrupt acknowledge register
#define MPEGDMA1_SRCADD 0x20025018 //bits:32 Access:W DESCR:DMA source pointer
#define MPEGDMA1_CNTRL 0x2002501c //bits:2 Access:R/W DESCR:Interrupt control register
#define MPEGDMA1_BLSIZE 0x20025020 //bits:16 Access:W DESCR:Data block dimension to be transferred
#define BMDMA_SRCADDRESS  0x20026000 //bits:32 Access:W DESCR:Block move DMA source address
#define BMDMA_DESTADDRESS 0x20026004 //bits:32 Access:W DESCR:Block move DMA destination address
#define BMDMA_COUNT 0x20026008 //bits:16 Access:W DESCR:Block move DMA counts
#define BMDMA_INTEN 0x2002600c //bits:1 Access:R/W DESCR:Block move DMA interrupt enable
#define BMDMA_STATUS 0x20026010 //bits:2 Access:R DESCR:Block move DMA status
#define BMDMA_INTACK 0x20026014 //bits:32 Access:W DESCR:Block move DMA interrupt acknowledge
#define BMDMA_ABORT 0x20026018 //bits:32 Access:W DESCR:Block move DMA abort
#define MOD_CONTROL 0x20027000 //bits:2 Access:R/W DESCR:MAFEIF control
#define MOD_STATUS 0x20027004 //bits:6 Access:R DESCR:MAFEIF status
#define MOD_INT_ENABLE 0x20027008 //bits:3 Access:R/W DESCR:Interrupt enable
#define MOD_ACK 0x2002700c //bits:8 Access:W DESCR:Acknowledge
#define MOD_BUFFER_SIZE 0x20027010 //bits:7 Access:R/W DESCR: Buffer size
#define MOD_MAFE_CTRL 0x20027014 //bits:8 Access:W DESCR:MAFE control
#define MOD_MAFE_STATUS 0x20027018 //bits:8 Access:R DESCR:MAFE status
#define MOD_RECEIVE0_POINTER 0x20027020 //bits:30 Access:R/W DESCR:Receive_memory_buffer_0 start address
#define MOD_RECEIVE1_POINTER 0x20027024 //bits:30 Access:R/W DESCR:Receive_memory_buffer_1 start address
#define MOD_TRANSMIT0_POINTER 0x20027028 //bits:30 Access:R/W DESCR:Transmit_memory_buffer_0 start address
#define MOD_TRANSMIT1_POINTER 0x2002702c //bits:30 Access:R/W DESCR:Transmit_memory_buffer_1 start address
#define FEI_IK0 0x20038000 //bits:8 Access:R/W DESCR:1 Intermediate Key
#define FEI_IK1 0x20038001 //bits:8 Access:R/W DESCR:1 Intermediate Key
#define FEI_IK2 0x20038002 //bits:8 Access:R/W DESCR:1 Intermediate Key
#define FEI_IK3 0x20038003 //bits:8 Access:R/W DESCR:1 Intermediate Key
#define FEI_IK4 0x20038004 //bits:8 Access:R/W DESCR:1 Intermediate Key
#define FEI_IKL 0x20038007 //bits:8 Access:W0 DESCR:Internal Key Load Register
#define FEI_TWH10 0x20038010 //bits:8 Access:W0 DESCR:Temporary Word High
#define FEI_TWH11 0x20038011 //bits:8 Access:W0 DESCR:Temporary Word High
#define FEI_TWH12 0x20038012 //bits:8 Access:W0 DESCR:Temporary Word High
#define FEI_TWH13 0x20038013 //bits:8 Access:W0 DESCR:Temporary Word High
#define FEI_TWH14 0x20038014 //bits:8 Access:W0 DESCR:Temporary Word High
#define FEI_TWL18 0x20038018 //bits:8 Access:W0 DESCR:Temporary Word Low
#define FEI_TWL19 0x20038019 //bits:8 Access:W0 DESCR:Temporary Word Low
#define FEI_TWL1A 0x2003801a //bits:8 Access:W0 DESCR:Temporary Word Low
#define FEI_TWL1B 0x2003801b //bits:8 Access:W0 DESCR:Temporary Word Low
#define FEI_TWL1C 0x2003801c //bits:8 Access:W0 DESCR:Temporary Word Low
#define FEI_IF 0x2003803f //bits:6 Access:W0 DESCR:Internal Function
#define LNK_STREAM_FRAM 0x200384fc //bits:32 Access:R/W DESCR:End of Filter Data (FRAM) register - 320words from LNKBaseAddress
#define LNK_STREAM1_CONF1 0x20038580 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF2 0x20038584 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF3 0x20038588 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF4 0x2003858c //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF5 0x20038590 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF6 0x20038594 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF7 0x20038598 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF8 0x2003859c //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF9 0x200385a0 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF10 0x200385a4 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF11 0x200385a8 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF12 0x200385ac //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF13 0x200385b0 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF14 0x200385b4 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF15 0x200385b8 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF16 0x200385bc //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF17 0x200385c0 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF18 0x200385c4 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF19 0x200385c8 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF20 0x200385cc //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF21 0x200385d0 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF22 0x200385d4 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF23 0x200385d8 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF24 0x200385dc //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF25 0x200385e0 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF26 0x200385e4 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF27 0x200385e8 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF28 0x200385ec //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF29 0x200385f0 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF30 0x200385f4 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF31 0x200385f8 //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM1_CONF32 0x200385fc //bits:32 Access:R/W DESCR:Stream Configuration #1 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF1 0x20038600 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF2 0x20038604 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF3 0x20038608 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF4 0x2003860c //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF5 0x20038610 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF6 0x20038614 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF7 0x20038618 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF8 0x2003861c //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF9 0x20038620 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF10 0x20038624 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF11 0x20038628 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF12 0x2003862c //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF13 0x20038630 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF14 0x20038634 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF15 0x20038638 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF16 0x2003863c //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF17 0x20038640 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF18 0x20038644 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF19 0x20038648 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF20 0x2003864c //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF21 0x20038650 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF22 0x20038654 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF23 0x20038658 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF24 0x2003865c //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF25 0x20038660 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF26 0x20038664 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF27 0x20038668 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF28 0x2003866c //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF29 0x20038670 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF30 0x20038674 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF31 0x20038678 //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM2_CONF32 0x2003867c //bits:32 Access:R/W DESCR:Stream Configuration #2 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF1 0x20038680 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF2 0x20038684 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF3 0x20038688 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF4 0x2003868c //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF5 0x20038690 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF6 0x20038694 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF7 0x20038698 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF8 0x2003869c //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF9 0x200386a0 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF10 0x200386a4 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF11 0x200386a8 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF12 0x200386ac //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF13 0x200386b0 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF14 0x200386b4 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF15 0x200386b8 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF16 0x200386bc //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF17 0x200386c0 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF18 0x200386c4 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF19 0x200386c8 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF20 0x200386cc //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF21 0x200386d0 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF22 0x200386d4 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF23 0x200386d8 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF24 0x200386dc //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF25 0x200386e0 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF26 0x200386e4 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF27 0x200386e8 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF28 0x200386ec //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF29 0x200386f0 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF30 0x200386f4 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF31 0x200386f8 //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM3_CONF32 0x200386fc //bits:32 Access:R/W DESCR:Stream Configuration #3 (see pag.176 Reg.Man.)
#define LNK_STREAM_IRQ1 0x20038700 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ2 0x20038704 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ3 0x20038708 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ4 0x2003870c //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ5 0x20038710 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ6 0x20038714 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ7 0x20038718 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ8 0x2003871c //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ9 0x20038720 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ10 0x20038724 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ11 0x20038728 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ12 0x2003872c //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ13 0x20038730 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ14 0x20038734 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ15 0x20038738 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ16 0x2003873c //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ17 0x20038740 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ18 0x20038744 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ19 0x20038748 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ20 0x2003874c //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ21 0x20038750 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ22 0x20038754 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ23 0x20038758 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ24 0x2003875c //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ25 0x20038760 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ26 0x20038764 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ27 0x20038768 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ28 0x2003876c //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ29 0x20038770 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ30 0x20038774 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ31 0x20038778 //bits:32 Access:R/W DESCR:Stream IRQ Register
#define LNK_STREAM_IRQ32 0x2003877c //bits:32 Access:R/W DESCR:Stream IRQ Register
#define FEI_DEC_DAT 0x20038780 //bits:8 Access:R/W DESCR:Decryption Cell Register - Data
#define FEI_DEC_IDX_STA 0x20038784 //bits:6 Access:R/W DESCR:[WO:6]Decryption Cell Register - Index [RO:2]Decryption Cell Register - Status
#define FEI_SUB 0x20038788 //bits:16 Access:RO DESCR:Contents the 16 bits subcode value from the subcode FIFO
#define FEI_SFF 0x2003878c //bits:8 Access:RO DESCR:Indicates the actual filling level of the subcode FIFO
#define FEI_GCF 0x20038790 //bits:16 Access:RO DESCR:Module Configuration Flags
#define FEI_SLG 0x20038798 //bits:16 Access:R/W DESCR:Only used when data are input using the parallel interface
#define FEI_REV 0x2003879c //bits:8 Access:RO DESCR:Revision ID
#define FEI_ATAPI_CFG 0x200387a0 //bits:8 Access:R/W DESCR:ATAPI interface configuration
#define FEI_SE_RST 0x20038800 //bits:1 Access:WO DESCR:Reset Module
#define FEI_SE_SAC 0x20038804 //bits:1 Access:R/W DESCR:Sector Address Check
#define FEI_SE_MOD 0x20038808 //bits:1 Access:R/W DESCR:Sector Processor Mode
#define FEI_SE_CAPEN 0x2003880c //bits:1 Access:R/W DESCR:Capturing Enable
#define FEI_SE_EMR 0x20038810 //bits:1 Access:R/W DESCR:Error Mode
#define FEI_SE_IR 0x20038814 //bits:8 Access:R/W DESCR:Interrupt
#define FEI_SE_STAT 0x20038818 //bits:1 Access:RO DESCR:Status
#define FEI_SE_CAP_H 0x20038820 //bits:8 Access:R/W DESCR:Address of first sector /subcode block to be captured
#define FEI_SE_CAP_L 0x20038824 //bits:8 Access:R/W DESCR:Address of first sector /subcode block to be captured
#define FEI_SE_LST_H 0x20038828 //bits:8 Access:R/W DESCR:Address of (last + 1) sector /subcode block to be captured
#define FEI_SE_LST_L 0x2003882c //bits:16 Access:R/W DESCR:Address of (last + 1) sector/subcode block to be captured
#define FEI_SE_CUR_H 0x20038830 //bits:8 Access:RO DESCR:Address of sector/subcode block actually entering the SP
#define FEI_SE_CUR_L 0x20038834 //bits:16 Access:RO DESCR:Address of sector /subcode block entering the SP
#define FEI_SE_HE_H 0x20038860 //bits:16 Access:R/W DESCR:CPR_MAI Bits of Current Sector actually entering the SP
#define FEI_SE_HE_M 0x20038864 //bits:16 Access:R/W DESCR:CPR_MAI Bits of Current Sector actually entering the SP
#define FEI_SE_HE_L 0x20038868 //bits:16 Access:R/W DESCR:CPR_MAI Bits of Current Sector actually entering the SP
#define LNK_HDD_BUFSIZE 0x20038900 //bits:13 Access:R/W DESCR:Buffer size
#define LNK_HDD_ADDSTOP 0x20038904 //bits:16 Access:R/W DESCR:Write limit address
#define LNK_HDD_ADDRBANK 0x20038908 //bits:4 Access:R/W DESCR:High part of the incoming address
#define LNK_HDD_ADDRHIGH 0x2003890c //bits:9 Access:R/W DESCR:High part of the incoming address
#define LNK_STREAM_EN0 0x20038f40 //bits:1 Access:R/W DESCR:Stream 0 enable
#define LNK_STREAM_EN1 0x20038f41 //bits:1 Access:R/W DESCR:Stream 1 enable
#define LNK_STREAM_EN2 0x20038f42 //bits:1 Access:R/W DESCR:Stream 2 enable
#define LNK_STREAM_EN3 0x20038f43 //bits:1 Access:R/W DESCR:Stream 3 enable
#define LNK_STREAM_EN4 0x20038f44 //bits:1 Access:R/W DESCR:Stream 4 enable
#define LNK_STREAM_EN5 0x20038f45 //bits:1 Access:R/W DESCR:Stream 5 enable
#define LNK_STREAM_EN6 0x20038f46 //bits:1 Access:R/W DESCR:Stream 6 enable
#define LNK_STREAM_EN7 0x20038f47 //bits:1 Access:R/W DESCR:Stream 7 enable
#define LNK_STREAM_EN8 0x20038f48 //bits:1 Access:R/W DESCR:Stream 8 enable
#define LNK_STREAM_EN9 0x20038f49 //bits:1 Access:R/W DESCR:Stream 9 enable
#define LNK_STREAM_EN10 0x20038f4a //bits:1 Access:R/W DESCR:Stream 10 enable
#define LNK_STREAM_EN11 0x20038f4b //bits:1 Access:R/W DESCR:Stream 11 enable
#define LNK_STREAM_EN12 0x20038f4c //bits:1 Access:R/W DESCR:Stream 12 enable
#define LNK_STREAM_EN13 0x20038f4d //bits:1 Access:R/W DESCR:Stream 13 enable
#define LNK_STREAM_EN14 0x20038f4e //bits:1 Access:R/W DESCR:Stream 14 enable
#define LNK_STREAM_EN15 0x20038f50 //bits:1 Access:R/W DESCR:Stream 15 enable
#define LNK_STREAM_EN16 0x20038f51 //bits:1 Access:R/W DESCR:Stream 16 enable
#define LNK_STREAM_EN17 0x20038f52 //bits:1 Access:R/W DESCR:Stream 17 enable
#define LNK_STREAM_EN18 0x20038f53 //bits:1 Access:R/W DESCR:Stream 18 enable
#define LNK_STREAM_EN19 0x20038f54 //bits:1 Access:R/W DESCR:Stream 19 enable
#define LNK_STREAM_EN20 0x20038f55 //bits:1 Access:R/W DESCR:Stream 20 enable
#define LNK_STREAM_EN21 0x20038f56 //bits:1 Access:R/W DESCR:Stream 21 enable
#define LNK_STREAM_EN22 0x20038f57 //bits:1 Access:R/W DESCR:Stream 22 enable
#define LNK_STREAM_EN23 0x20038f58 //bits:1 Access:R/W DESCR:Stream 23 enable
#define LNK_STREAM_EN24 0x20038f59 //bits:1 Access:R/W DESCR:Stream 24 enable
#define LNK_STREAM_EN25 0x20038f5a //bits:1 Access:R/W DESCR:Stream 25 enable
#define LNK_STREAM_EN26 0x20038f5b //bits:1 Access:R/W DESCR:Stream 26 enable
#define LNK_STREAM_EN27 0x20038f5c //bits:1 Access:R/W DESCR:Stream 27 enable
#define LNK_STREAM_EN28 0x20038f5d //bits:1 Access:R/W DESCR:Stream 28 enable
#define LNK_STREAM_EN29 0x20038f5e //bits:1 Access:R/W DESCR:Stream 29 enable
#define LNK_STREAM_EN30 0x20038f5f //bits:1 Access:R/W DESCR:Stream 30 enable
#define LNK_STREAM_EN31 0x20038f60 //bits:1 Access:R/W DESCR:Stream 31 enable
#define LNK_STAT 0x20038f80 //bits:21 Access:R/W DESCR:Status register
#define LNK_STAT_FIFO 0x20038f84 //bits:32 Access:R DESCR:FIFO status word
#define LNK_PACKET_LENGTH 0x20038f88 //bits:12 Access:R/W DESCR: Number of bytes per packet
#define LNK_MODE 0x20038f90 //bits:9 Access:R/W DESCR:Mode
#define LNK_PCR_STREAM 0x20038f94 //bits:6 Access:R/W DESCR: PCR stream
#define LNK_AF1-0 0x20038f98 //bits:32 Access:R DESCR:Adaptation field bytes 0 to 3
#define LNK_AF1-0 0x20038f9c //bits:32 Access:R DESCR:Adaptation field bytes 4 to 7
#define LNK_V_PTS 0x20038fa0 //bits:32 Access:R DESCR:Video time stamp
#define LNK_A_PTS 0x20038fa4 //bits:32 Access:R DESCR:Audio time stamp
#define LNK_PCR 0x20038fa8 //bits:32 Access:R DESCR:PCR
#define LNK_PCR_EXT 0x20038fac //bits:9 Access:R DESCR:PCR extension
#define LNK_AR_SIZE 0x20038fb0 //bits:6 Access:R/W DESCR:AR size
#define LNK_SDAV_CONF 0x20038fb4 //bits:27 Access:R/W DESCR:SDAV configuration
#define LNK_SDAV_DMA_EN 0x20038fb8 //bits:6 Access:R/W DESCR:SDAV DMA enable
#define LNK_SDAV_DATA 0x20038fbc //bits:32 Access:R/W DESCR:SDAV data
#define LNK_EN_LINK 0x20038fc0 //bits:1 Access:R/W DESCR:Enable link
#define LNK_EXTRA_BITS 0x20038fc8 //bits:13 Access:R/W DESCR:Extra bits
#define ENDREGS 0x5fffffff //bits:0 Access:?? DESCR:??
