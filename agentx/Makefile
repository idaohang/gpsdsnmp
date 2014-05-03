


generate: ../mib/GPSD-MIB.mib
	MIBDIRS="+." MIBS="+MONIT-MIB"


TARGET=gpsdsnmp
OBJS=$(TARGET).o gpsdFix/gpsdFix.o

CFLAGS=-I. `net-snmp-config --cflags`
BUILDLIBS=`net-snmp-config --libs`
BUILDAGENTLIBS=`net-snmp-config --agent-libs`
LDFLAGS=-fPIC -shared

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(BUILDAGENTLIBS)

$(TARGET).o: $(TARGET).c Makefile
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $(TARGET).o $(TARGET).c

gpsdFix/gpsdFix.o: gpsdFix/gpsdFix.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $<
