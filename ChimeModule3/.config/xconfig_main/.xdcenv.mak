#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/grace_3_10_00_82/packages;C:/ti/msp430/msp430_driverlib_2_60_00_02/packages;C:/ti/msp430/msp430_driverlib_2_60_00_02;C:/ti/ccsv6/ccs_base;C:/Users/a0225935/workspace_v6_1/ChimeModule3/.config
override XDCROOT = C:/ti/xdctools_3_31_01_33_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/grace_3_10_00_82/packages;C:/ti/msp430/msp430_driverlib_2_60_00_02/packages;C:/ti/msp430/msp430_driverlib_2_60_00_02;C:/ti/ccsv6/ccs_base;C:/Users/a0225935/workspace_v6_1/ChimeModule3/.config;C:/ti/xdctools_3_31_01_33_core/packages;..
HOSTOS = Windows
endif
