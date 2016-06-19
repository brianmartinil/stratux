/*
METAR Decoder Software Package Library: Parses Aviation Routine Weather Reports
Copyright (C) 2003  Eric McCarthy

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "metar_structs.h"
#ifdef SYNOPTIC
 
char *BldSynop( Decoded_METAR * , char * );
/*char *Sec0MeSm(Decoded_METAR *);*/
/*char *Sec1MeSm(Decoded_METAR *, char *);*/
/*char *Sec3MeSm(Decoded_METAR *, char *);*/
/*char *Sec5MeSm(Decoded_METAR *, char *);*/
#endif
 
void prtDMETR( Decoded_METAR *);
int DcdMETAR( char *, Decoded_METAR * );
 
#pragma page(1)
#pragma subtitle(" ")
#pragma subtitle("subtitle - description                       ")
/********************************************************************/
/*                                                                  */
/*  Title:         dRVMETAR                                         */
/*  Organization:  W/OSO242 - GRAPHICS AND DISPLAY SECTION          */
/*  Date:          28 Oct 1994                                      */
/*  Programmer:    CARL MCCALLA                                     */
/*  Language:      C/370                                            */
/*                                                                  */
/*  Abstract:      DRVMETAR is a main routine that acts a driver    */
/*                 for testing the METAR Decoder function.          */
/*                                                                  */
/*  External Functions Called:                                      */
/*                 None.                                            */
/*                 DcdMETAR                                         */
/*                 prtDcdMetar                                      */
/*                 Sec0MTSm                                         */
/*                 Sec1MTSm                                         */
/*                                                                  */
/*  Input:         None                                             */
/*                                                                  */
/*  Output:        None                                             */
/*                                                                  */
/*  Modification History:                                           */
/*                 None.                                            */
/*                                                                  */
/********************************************************************/
#pragma page(1)
main()
{
   static char *string[] =
  {

"KMKG 18022G29KT 3SM BR BKN018 BR 24/22 A2995 RMK A02 VIS 2",
 
 
"KPIT 132351Z 33013KT 4SM +TSRA BR BKN018CB OVC031 12/11 A2977 RMK "
"AO2 PK WND 31041/2305 WSHFT 2300 PRESSRR SLP090 FRQ LTGCGCC OHD "
"TS OHD MOV E CB OHD MOV E 8/3// P0051 60052 T01170111 10222 20122 "
"53030",
 
 
"KCAK 132351Z 28016G22KT 10SM BKN021 OVC030 11/09 A2981 RMK AO2 "
"TSE00RAE10 PRESRR SLP093 TS MOV NE CIG RGD 8/5// P0002 60066 "
"T01110094 10217 20111 51053",
 
"KBUF 132354Z 21007KT 3SM +TSRA BR FEW009 OVC 12/11 A2959 RMK "
"AO2 PRESFR SLP021 8/9// TS ALQDS MOV E OCNL LTGICCCCG P0031 "
"60073 T01170111 10233 20111 50000 0",
 
 
"KPIT 132356Z 32012G21KT 4SM TSRA BR BKN018CB OVC031 12/11 A2978 "
"RMK AO2 WSHFT 2338 PRESFR FRQ LTGCGCC OHD TS OHD MOV E CB OHD MOV "
"E P0001",
 
 
"KCAK 132358Z 28015G22KT 10SM BKN013 OVC023 11/10 A2982 RMK AO2",
 
"KBUF 140001Z 22008KT 3SM +TSRA BR BKN009 BKN013 OVC022 12/12 A2959 "
"RMK AO2 P0003",
 
 
 
"KRIL 031853Z AUTO 33008KT 10SM SCT022 BKN032 OVC060 07/01 A3004 "
"RMK AO2 SLP157 T00720006 TSNO",
 
 
"METAR KCLE 091657Z COR 35021KT 3SM -PL SHPL VV004 M03/M04 A2964 "
"RMK VIS S M1/4=",
 
"METAR KCLE 091657Z COR 35021KT 3SM -PE SHPE VV004 M03/M04 A2964 "
"RMK VIS S M1/4=",
 
"METAR KCLE 091657Z COR 35021KT 3SM -PE TSPL VV004 M03/M04 A2964 "
"RMK VIS S M1/4=",
 
"METAR KCLE 091657Z COR 35021KT 3SM -PL TSPE VV004 M03/M04 A2964 "
"RMK VIS S M1/4=",
 
 
"KMLB 200450Z 18006KT 7SM OVC100 23/22 A2986 RMK FQT LTGIG W-N",
 
"KMLB 200450Z 18006KT 7SM OVC100 23/22 A2986 RMK FQT LTGIG W-N=",
 
"KMLB 200450Z 18006KT 7SM OVC100 23/22 A2986 RMK FRQ LTGIC NW",
 
"KMLB 200450Z 18006KT 7SM OVC100 23/22 A2986 RMK FRQ LTGCC NW=",
 
 
"SPECI KEKO 151609Z 00000KT 5SM BR FEW003 SCT013 M04/M06 A3018 "
"RMK VIS N-NE M1/4",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/MM A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB MM/M12 A2992",
 
 "METAR KLAX 281156Z AUTO VRB100G135KT 130V210 3 9999 "
 "R15L/0500FT R22L/2700FT R16/1200FT R34/1000V1600FT R01L/P6000FT FC "
 "+TS VCTS FEW/// SCT000 BKN050 SCT150 OVC250 3/M1 A2991 RMK "
 "TORNADO B13 DSNT NE A01 PK WND 18515/45 "
 "WSHFT 1350 FROPA TWR VIS 1 1/2 SFC VIS 1/4 VIS 1/4V1 1/4 "
 "VIS 2 1/2 RWY11 "
 "DVR/1000V1600FT "
 "SHRAB05E30SHSNB20E55 FZDZB1057E1059 CIG 1000V1500 CIG 020 RWY11 "
 "PRESFR PRESRR SLP013 FG FEW/// HZ SCT000 VIS NW 2 1/2 GR 3/4 "
 "VIRGA SE -XRAFG3 CIGE005 BKN014 V OVC "
 "FU BKN020 NOSPECI LAST 8/365 SNINCR 2/10 4/178 "
 "933125 98096 P0125 60225 70565 "
 "T00261015 10369 21026 "
 "404800360 52101 VISNO RWY05 CHINO RWY27 PNO RVRNO "
 "PWINO FZRANO TSNO $",
 
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK SLP046 ESTMD SLP VIS SW-NW 2 "
 "PWINO FZRANO TSNO $",
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK SLP046 ESTMD SLP VIS SW-NW 2 1/2 "
 "PWINO FZRANO TSNO $",
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK SLP046 ESTMD SLP VIS SW-NW 2",
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK SLP046 ESTMD SLP VIS SW-NW 2 1/2=",
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK SLP046 ESTMD SLP VIS SW-NW 2",
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK CIG 003V026 SLP046 ESTMD SLP VIS SW-NW 2",
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK VIS S 2",
 
"SPECI KEKO 151609Z 00000KT 5SM BR FEW003 SCT013 M04/M06 A3018 "
"RMK VIS N-NE 1",
 
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/MM A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB MM/M12 A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB M18/MM A2992",
 
 
 
 
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK CIG 003V026 SLP046 ESTMD SLP VIS SW-NW 2=",
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK VIS S 2=",
 
"SPECI KEKO 151609Z 00000KT 5SM BR FEW003 SCT013 M04/M06 A3018 "
"RMK VIS N-NE 1=",
 
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK SLP046 ESTMD SLP VIS SW-NW 2",
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK CIG 003V026 SLP046 ESTMD SLP VIS SW-NW 2",
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK VIS S 2",
 
"SPECI KEKO 151609Z 00000KT 5SM BR FEW003 SCT013 M04/M06 A3018 "
"RMK VIS N-NE 1",
 
 
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK SLP046 ESTMD SLP VIS SW 2",
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK CIG 003V026 SLP046 ESTMD SLP VIS NW 2",
 
"METAR KAFF 091657Z COR 35021KT 3SM -SG BR VV004 M03/M04 A2964 "
"RMK VIS S 2",
 
"SPECI KEKO 151609Z 00000KT 5SM BR FEW003 SCT013 M04/M06 A3018 "
"RMK VIS NE 1",
 
 
 "KPIT 1935Z 22015G25KT 1/8SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/12 A2992",
 
 "KPIT 1935Z 22015G25KT 6SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB M12/M18 A2992",
 
 "KPIT 1935Z 22015G25KT 8SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB M18/12 A2992",
 
 "KPIT 1935Z 22015G25KT 9SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/M01 A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005TCU BKN010ACSL OVC250CB MM/12 A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/MM A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB MM/M12 A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB M18/MM A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB MM/MM A2992",
 
  "SPECI KGFI 041430Z 18045G56KT M1/4SM R15/0200FT FC +TS VV010 20/18 "
  "A2900 RMK A02A PK WND 18056/28 OCNL LTG AP "
  "RAB15E25TSB20 FCB1430 PRESFR "
  "SLP 701 P 0254 T01990182",
 
 
 "METAR KLAX 281156Z AUTO VRB100G135KT 130V210 3 9999 "
 "R15L/0500FT R22L/2700FT R16/1200FT R34/1000V1600FT R01L/P6000FT FC "
 "+TS VCTS FEW/// SCT000 BKN050 SCT150 OVC250 3/M1 A2991 RMK "
 "TORNADO B13 DSNT NE A01 PK WND 18515/45 "
 "WSHFT 1350 FROPA TWR VIS 1 1/2 SFC VIS 1/4 VIS 1/4V1 1/4 "
 "VIS 2 1/2 RWY11 "
 "DVR/1000V1600FT "
 "SHRAB05E30SHSNB20E55 FZDZB1057E1059 CIG 1000V1500 CIG 020 RWY11 "
 "PRESFR PRESRR SLP013 FG FEW/// HZ SCT000 VIS NW 2 1/2 GR 3/4 "
 "VIRGA SE -XRAFG3 CIGE005 BKN014 V OVC "
 "FU BKN020 NOSPECI LAST 8/365 SNINCR 2/10 4/178 "
 "933125 98096 P0125 60225 70565 "
 "T00261015 10369 21026 "
 "404800360 52101 VISNO RWY05 CHINO RWY27 PNO RVRNO "
 "PWINO FZRANO TSNO $",
 
 "KP88 1919Z 09001KT 14/03 RMK AO / PKWND 002/RNO 158 Z T01440034",
 
 "K40B 1924Z 29004KT 15/M07 RMK AO PKWND 011/RM MV263 T01501072",
 
 
 
 "SPECI KGFI 041430Z COR 18045G56KT  "
 "M1/4SM R15/0200FT R01L/0600V1000FT R01L/M0600FT R27/P6000FT "
 "+FC +TS -FZDZ VV010 04/M02 "
 "A2900 RMK TORNADO B13 6 NE A02A PK WND 18056/28 WSHFT 30 FROPA "
 "TWR VIS 1 1/2 VIS NE 2 1/2 VIS 2 1/2 RWY11 DVR/0600V1000FT "
 "OCNL LTGICCG OVHD RAB15E25 TSB20 FCB1430 TS SE MOV NE GR 1 3/4 "
 "VIRGA SW CIG 005V010 FG SCT000 BKN014 V OVC CB DSNT W "
 "CIG 002 RWY11 PRESFR PRESRR "
 "SLP701 ACFT MSHP NOSPECI SNINCR 2/10 FIRST "
 "P0254 60217 70125 4/021 933036 8/903 98096 T00261015 "
 "11021 21001 401120084 52032RVRNO PWINO PNO FZRANO TSNO "
 "VISNO RWY06 CHINO RWY12 $",
 
 
 
"KPHX 281156Z 12004KT 16KM CLR 15/05 A2996 RMK AOA SLP135 T01500050 "
"10250 20150 53006",
"KFCA 281156Z 30003KT 10SM CLR 06/02 A3009 RMRK AO TNO $ SLP191 "
"T00610023 10167 20056 53003",
"KAST 281156Z 00000KT 10SM BKN095 09/08 A2997 REMARK AOA SLP150 "
"T00940084 10161 20094 52005 ",
"KHVR 281156Z 03003KT 10SM OVC020 09/07 A3010 REMARKS AO TNO ZRNO "
"$ SLP194 T00940073 10156 20089 51005",
 
"KGGW 281156Z 35006KT 5SM BR OVC010 10/09 A3003 RMK AOA $ SLP177 "
"70003 T01000095 10156 20110 53008",
"KELY 1153Z AUTO 14004KT 10SM SCT075 01/M01 A3011 RMK AOA TNO ZRNO "
"SLP171 70001 T00061011 10139 21006 51005",
"KFLG 281156Z 29006KT 10SM CLR 04/M01 A3012 RMK AO TNO SLP147 "
"T00391011 21006 51004",
"KGTF 281156Z 27005KT 7SM BKN080 04/04 A3010 RMK AOA SLP205 "
"T00440045 10117 20039 51006",
"KHLN 281156Z AUTO 27005KT 10SM OVC023 07/05 A3011 RMK AOA OVC V "
"BKN $ SLP202 60000 70001 T00670050 10122 20061 53003",
 
"K13A 1918Z 20011KT 26/M06 RMK AO PKWND 020/RNO 644V264 T02611061",
 
 
   "KGGW 1756Z 33018KT 10SM OVC015 M03/M06 A3041 RMK AOA SLP338 "
   "4/007 60002 T10281055 11028 21072 51009",
   "KPHX 1756Z 130004KT 10SM CLR 18/M03 A3001 RMK AOA SLP154 "
   "T01781033 10178 20067 58007",
   "KFCA 1756Z 29005KT 10SM CLR 05/M11 A3049 RMK AOA TNO SLP352 "
   "T00501111 10050 21044 50004",
   "KAST 1756Z 01006KT 10SM CLR 11/04 A3047 RMK AOA SLP316 "
   "T01110045 10111 20000 50002",
   "KHVR 1756Z 31007KT 5SM -SN SCT011 BKN024 OVC030 M05/M08 A3056 "
   "RMK AOA 933004 "
   "BKN V SCT TNO P0000 $ SLP389 4/015 60002 "
   "T10501077 11050 21078 51010",
   "KELY 1753Z 34010KT 10SM CLR 01/M07 A3022 RMK AOA TNO FZRNO "
   "SLP240 T00111066 10011 21078 58007",
   "KFLG 1756Z 07006KT 10SM CLR 06/M12 A3009 RMK AO TNO FZRNO "
   "SLP178 T00561122 10061 21100 58005",
   "KGTF 1756Z 35010KT 1/2SM -SN FG VV09 M06/M08 A3051 RMK AOA "
   "933004 SFC VSBY 3/4 "
   "P0009 SLP393 60010 T10611077 11044 21067 53013",
   "KHLN 1756Z 35012KT 10SM SCT032 OVC060 M02/M09 A3048 RMK AOA "
   "SLP369 60000 T10171094 11017 21061 53006",
   "KAST 1756Z 01006KT 10SM CLR 11/04 A3047 RMK AOA SLP316 61104 "
   "71235 T01110045 10111 20000 401720056 58002",
  "METAR KLAX 04281156Z AUTO VRB100G135KT 130V210 3 1/2SM "
  "R15L/0500FT R22L/2700FT R16/1200FT R34/1000V1600FT R01L/P6000FT FC "
  "+TS BLPY FEW000 BKN050 SCT150 OVC250 3/M1 A2991 RMK "
  "TORNADO B13 DSNT NE A02 PK WND 18515/45 "
  "WSHFT 1350 FROPA TWR VIS 1 1/2 SFC VIS 1/4 VIS 1/4V1 1/4 "
  "VIS 2 1/2 RWY11 OCNL LTG VCY STN "
  "RAB1030E1145 FZDZE56 BLPYE57 CIG 1000V1500 CIG 020 RWY11 "
  "PRESFR PRESRR SLP013 FG FEW000 VIS NW2 1/2 GR 3/4 "
  "VIRGA SE -XRAFG3 CIGE005 BKN014 V OVC "
  "FU BKN020 NOSPECI LAST 8/365 SNINCR 2/10 4/178 "
  "933125 98096 P0125 60225 70565 "
  "T00261015 10369 21026 "
  "404800360 52101 PWINO FZRANO TSNO $",
 
 
 
  "METAR KGFI 041356Z AUTO 17012KT 130V210 3 1/2SM R15L/0500FT -RA "
  "SCT050 OVC110 26/18 A2991 RMK FUNNEL CLOUDS A02 RAB30 "
  "SLP 101 GR M1/4 VIRGA SCT V BKN P 0010 T02640178",
 
  "METAR KGFI 041356Z AUTO 05008KT 10SM R15L/P6000FT CLR A2991 "
  "RMK WATERSPOUTS VCY STN NW A02 SLP 101 10288 20243 52021 $ ",
 
  "SPECI KGFI 041420Z AUTO 18030KT 3 1/2SM RVRNO TS -RA BKN008 OVC060 "
  "26/22 A2991 RMK A02 RA15TSB20 PRESFR SLP 101 P 0000 T02640218",
 
  "KABE 281900Z NIL",
 
  "METAR KPIT NIL",
 
  "METAR KCLE 04281156Z 170100G135KT 110V180  M1/4SM "
  "R01L/P6000FT +TSSHRA VCFG "
  "BKN025 SCT100 OVC200 M26/ A2991 RMK PK WND 18515/45 A02 "
  "WSHFT 1350 TWR VIS 1 1/2 SFC VIS 1/4 VIS 1/4V1 1/4 "
  "CIG 1000V1500 PRESFR FRQ LTG CG NW "
  "RAB1030E1145 FZDZE56 PRESRR SLP135 GS "
  "T1263 "
  "VIRGA NW 8/365 4/178 P 0125 60225 7//// 70565 10369 21026 "
  "404800360 52101 PWINO FZRANO TSNO $",
 
  "METAR KPHL 040256Z AUTO 170100G135KT 130V210  1/2SM "
  "R15L/0500FT R22L/2700FT R16/1200FT R34/1000V1600FT R01L/P6000FT "
  "FC +TS BKN050 SCT150 OVC250 M26/ A2991 RMK A02 PK WND 185150/1345 "
  "WSHFT 1350 TWR VIS 1 1/2 SFC VIS 1/4 VIS 1/4V1 1/4 LTG DSNT "
  "RAB1030E1145 FZDZE56 CIG 1000V1500 PRESFR PRESRR SLP037 GR 2 3/4 "
  "VIRGA E 8/365 4/178 P 0125 70565 21026 T0263 10369 60225 "
  "404800360 52101 PWINO FZRANO TSNO $",
 
  "SPECI KGFI 041420Z AUTO 18030KT 2 1/2SM RVRNO TS -RA BKN008 "
  "OVC060 25/22 A2991 RMK A02 LTG DSNT W "
  "RAB15TSB20 PRESFR SLP101 P 0000 "
  "254/218",
 
  "METAR KGFI 041356Z AUTO 170100G135KT 130V210 3 1/2SM "
  "R15L/0500FT R22L/2700FT R16/1200FT R34/1000V1600FT R01L/P6000FT "
  "FC +TS BKN050 SCT150 OVC250 M26/ A2991 RMK A02 PK WND 185150/1345 "
  "WSHFT 1350 TWR VIS 1 1/2 SFC VIS 1/4 VIS 1/4V1 1/4 "
  "RAB1030E1145 FZDZE56 CIG 1000V1500 PRESFR PRESRR SLP997 GR M1/4 "
  "VIRGA SE 8/365 4/178 P 0125 6//// 60225 70565 T0263 10369 21026 "
  "404800360 52101 PWINO FZRANO TSNO $",
 
 
 
  "METAR KGFI 041356Z AUTO 170100G135KT 130V210 3 1/2SM "
  "R15L/0500FT R22L/2700FT R16/1200FT R34/1000V1600FT R01L/P6000FT "
  "FC +TS BKN050 SCT150 OVC250 M26/ A2991 RMK A02 PK WND 185150/1345 "
  "WSHFT 1350 TWR VIS 1 1/2 SFC VIS 1/4 VIS 1/4V1 1/4 "
  "RAB1030E1145 FZDZE56 CIG 1000V1500 PRESFR PRESRR SLP997 GR 25 "
  "VIRGA 35 8/365 4/178 P 0125 6//// 60225 70565 T0263 10369 21026 "
  "VIRGA 35 8/365 4/178 P 0125 21026 70565 10369 60225 T0263 21026 "
  "404800360 52101 PWINO FZRANO TSNO $",
 
 
  "METAR KGFI 041356Z AUTO 170100G135KT 130V210 3 1/2SM "
  "R15L/0500FT R22L/2700FT R16/1200FT R34/1000V1600FT R01L/P6000FT "
  "FC +TS BKN050 SCT150 OVC250 3/M1 A2991 RMK A02 PK WND 18515/45 "
  "WSHFT 1350 TWR VIS 1 1/2 SFC VIS 1/4 VIS 1/4V1 1/4 "
  "RAB1030E1145 FZDZE56 CIG 1000V1500 PRESFR PRESRR SLP997 GR 25 "
  "VIRGA 35 8/365 4/178 P 0125 60225 70565 T00261015 10369 21026 "
  "404800360 52101 PWINO FZRANO TSNO $",
 
  "METAR KGFI 041356Z AUTO 170100G135KT 130V210 3 1/2SM "
  "R15L/0500FT R22L/2700FT R16/1200FT R34/1000V1600FT R01L/P6000FT "
  "FC +TS BKN050 SCT150 OVC250 3/M1 A2991 RMK A02 PK WND 185150/1345 "
  "WSHFT 1350 TWR VIS 1 1/2 SFC VIS 1/4 VIS 1/4V1 1/4 "
  "RAB1030E1145 FZDZE56 CIG 1000V1500 PRESFR PRESRR SLP997 GR 25 "
  "VIRGA 35 8/365 4/178 P 0125 60225 70565 T00261015 10369 21026 "
  "404800360 52101 PWINO FZRANO TSNO",
 
 
 
  "METAR KGFI 041356Z AUTO 05008KT 10SM R15L/P6000FT CLR A2991 RMK "
  "A02 SLP 101 10288 20243 52021",
  "SPECI DGFI 041430Z 18045G56KT M1/4SM R15/0200FT FC +TS VV010 20/18 "
  "M20/M18 A2900 RMK A02A PK WND 18056/28 RAB15E25TSB20 FCB1430 PRESFR "
  "SLP 701 P 0254 M199/M182",
 
  "SPECI DGFI 041430Z 18045G56KT M1/4SM R15/0200FT FC +TS VV010 20/18 "
  "M20/M18 A2900 RMK A02A PK WND 18056/28 RAB15E25TSB20 FCB1430 PRESFR "
  "SLP 701 P 0254 M199/182",
 
  "SPECI DGFI 041430Z 18045G56KT M1/4SM R15/0200FT FC +TS VV010 20/18 "
  "M20/M18 A2900 RMK A02A PK WND 18056/28 RAB15E25TSB20 FCB1430 PRESFR "
  "SLP 701 P 0254 199/M182",
 
 "METAR APIT 171755Z AUTO 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 4/369 58033 6003/ TWELVE 70125 10039 20029 410840112 "
 "PCPN 0009 8/563 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 1 1/2V2 SLP875 SGB1213E1225",
 
 "NZWN 1700Z 35030G49KT 320V030 20KM 02 5SC021 7SC046 12/08 "
 "          Q0994.2 TEMPO 6000 RA 5ST012 2CB015 RMK SLP056 "
 "RAE0123",
 
 "SPECI APIT 171755Z 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 58033 6003/ TWELVE 70125 8/321 10039 20029 410840112 "
 "PCPN 0009 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 1 SLP875 FGB1713",
 
 "APIT 1755Z 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 58033 6003/ TWELVE 70125 10039 20029 410840112 "
 "PCPN 0009 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 1V2 SLP875",
 
 
 "APIT 1755Z 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 58033 6003/ TWELVE 70125 10039 20029 410840112 "
 "PCPN 0009 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 1 1/2V2 1/2 SLP875",
 
 "APIT 1755Z 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 58033 6003/ TWELVE 70125 10039 20029 410840112 "
 "PCPN 0009 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 1V2 1/2 SLP875",
 
 
 "EGPF 1720Z 00000KT 9999 -SHRA STC014 SCT020CB BNK024 12/09 "
 "Q1003 NOSIG",
 
 "NZAA 1700Z 03010KT 30KM 03 5CU022 7SC035 11/07 Q1006.5 NOSIG",
 "NZWN 1700Z 35030G49KT 320V030 20KM 02 5SC021 7SC046 12/08 "
 "     Q0994.2 TEMPO 6000 RA 5ST012 2CB015 RMK KAUKAU 30050KT",
 "DGAA 1800Z 22012KT 9999 SCT009 BKN120 25/21 Q1015",
 "DAAT 1830Z 30010KT CAVOK 29/06 Q1019",
 
 "GQPP 1800Z 34023KT 3000 DRSA SKC 24/20 Q1011 NSG",
 "DAAG 1830Z 06006KT 9999 SCT020 25/22 Q1015",
 "DABB 1830Z 04010KT 9999 SCT030TCU SCT033CB 27/18 Q1017",
 "DABC 1830Z 00000KT 9999 SCT026TCU SCT036CB 22/18 Q1020 RETS",
 
 "NZAA 1700Z 03010KT 30KM 03 5CU022 7SC035 11/07 Q1006.5 NOSIG",
 "NZWN 1700Z 35030G49KT 320V030 20KM 02 5SC021 7SC046 12/08 "
 "          Q0994.2 TEMPO 6000 RA 5ST012 2CB015 RMK K",
 "NZWN 1700Z 35030G49KT 320V030 20KM 02 5SC021 7SC046 12/08 "
 "     Q0994.2 TEMPO 6000 RA 5ST012 2CB015 RMK KAUKAU 30050KT",
 "DGAA 1800Z 22012KT 9999 SCT009 BKN120 25/21 Q1015",
 
 "GFLL 1900Z NIL",
 
 "GOOY 1800Z 03006G17KT 340V080 6000 TSRA BKN016 BKN030CB "
 "BKN133 26/23 Q1013 NOSIG",
 
 "GCXO 1930Z 32018KT 8000 SCT003 SCT007 18/16 Q1019",
 
 "APIT 1755Z 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 58033 6003/ TWELVE 70125 10039 20029 410840112 "
 "PCPN 0009 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 1 1/2V2",
 
 "BPIT 1755Z 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 58033 6003/ TWELVE 70125 10039 20029 410840112 "
 "PCPN 0009 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 1V2",
 
 "CPIT 1755Z 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 58033 6003/ TWELVE 70125 10039 20029 410840112 "
 "PCPN 0009 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 1V2 1/2",
 
 "DPIT 1755Z 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 58033 6003/ TWELVE 70125 10039 20029 410840112 "
 "PCPN 0009 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 1 1/2V2 1/2",
 
 "EPIT 1755Z 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 58033 6003/ TWELVE 70125 10039 20029 410840112 "
 "PCPN 0009 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 1/2V3/4",
 
 "FPIT 1755Z 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 58033 6003/ TWELVE 70125 10039 20029 410840112 "
 "PCPN 0009 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 3/4V2 1/2",
 
 "GPIT 1755Z 22015G25KT 1 3/4SM R22L/2700FT R16/1200FT "
 "R34/1000V1600FT R01L/P6000FT R04RR/900FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/16 A2992 "
 "RMK 58033 6003/ TWELVE 70125 10039 20029 410840112 "
 "PCPN 0009 WSHFT 1715 PK WND 2032/1725 "
 "CIG 20V25 WND 12V25 TWR VIS 2 1/2 "
 "SFC VIS 1 1/2 VIS 3/4V3",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB M18/M16 A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB M18/16 A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB 18/M16 A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB MM/M16 A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB MM/16 A2992",
 
 "KPIT 1935Z 22015G25KT 1 3/4SM R22L/2700FT "
 "TSRA -DZ FG +SNPE SCT005 BKN010 OVC250CB M18/MM A2992",
 
 
        NULL};
 
   /***************************/
   /* DECLARE LOCAL VARIABLES */
   /***************************/
 
   Decoded_METAR Metar;
   Decoded_METAR *Mptr = &Metar;
   int j,
       ErReturn;
   static char *synopRTRN = NULL;
   char bltn_prefix[20];
 
   /***************************************************/
   /* START BODY OF MAIN ROUTINE FOR CALLING DcdMETAR */
   /***************************************************/
 
   j = 0;
 
   while( string[j] != NULL)
   {
            /*-- PRINT INPUT METAR REPORT ----------------------------*/
      printf("\n\nINPUT METAR REPORT:\n\n %s\n\n",string[j] );
 
            /*-- DECODE INPUT REPORT ---------------------------------*/
      if ( (ErReturn = DcdMETAR( string[ j ], Mptr )) != 0 )
         printf("DcdMETAR:  Error Return Number: %d\n",ErReturn);
 
            /*-- PRINT DECODED METAR REPORT ELEMENTS -----------------*/
      printf("\n\nFINAL DECODED PRODUCT...\n\n");
      prtDMETR( Mptr );
#ifdef OLDSTUFF
/************************************************/
/*  Convert Decoded METAR into Synoptic format  */
/************************************************/
 
      printf("Just after call to prtDMETR\n");
 
               sprintf( bltn_prefix, "AAXX YYGGi##," );
               synopRTRN = BldSynop( Mptr, bltn_prefix );
            printf("After BldSynop, SynopRep =:\n%s\n",synopRTRN);
            /**********************************************************/
            /*-- ENCODE SECTION 0 OF THE SYNTHETIC SYNOPTIC REPORT ---*/
            /**********************************************************/
      printf("Just before call to Sec0MeSM\n");
 
      if( (synopRTRN = Sec0MeSm( Mptr )) == NULL )
         printf("Sec0MeSm returned a NULL pointer\n");
      else
         printf("After Sec0MeSm: %s\n",synopRTRN);
 
            /**********************************************************/
            /*-- ENCODE SECTION 1 OF THE SYNTHETIC SYNOPTIC REPORT ---*/
            /**********************************************************/
      if( synopRTRN != NULL )
         synopRTRN = Sec1MeSm( Mptr,synopRTRN );
            printf("After Sec1MeSm: %s\n",synopRTRN);
 
            /**********************************************************/
            /*-- ENCODE SECTION 3 OF THE SYNTHETIC SYNOPTIC REPORT ---*/
            /**********************************************************/
 
      if( synopRTRN != NULL )
         synopRTRN = Sec3MeSm( Mptr,synopRTRN );
            printf("After Sec3MeSm: %s\n",synopRTRN);
 
            /**********************************************************/
            /*-- ENCODE SECTION 5 OF THE SYNTHETIC SYNOPTIC REPORT ---*/
            /**********************************************************/
 
      if( synopRTRN != NULL )
         synopRTRN = Sec5MeSm( Mptr,synopRTRN);
            printf("After Sec5MeSm: %s\n",synopRTRN);
 
            /**********************************************************/
            /*-- PRINT THE ENCODED SYNTHETIC SYNOPTIC REPORT ---------*/
            /**********************************************************/
 
      if( synopRTRN != NULL ) {
         printf("\n\nOutput Synoptic Report:  %s\n\n",synopRTRN);
         free( synopRTRN);
      }
 
#endif
 
      j++;
 
   }
 
}
