# invoke SourceDir generated makefile for main.pe430
main.pe430: .libraries,main.pe430
.libraries,main.pe430: package/cfg/main_pe430.xdl
	$(MAKE) -f C:\Users\a0225935\workspace_v6_1\ChimeModule3/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\a0225935\workspace_v6_1\ChimeModule3/src/makefile.libs clean

