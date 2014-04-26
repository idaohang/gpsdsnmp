
MIBFILE=GPSD-MIB
SMIPATH=/usr/share/snmp/mibs:.

all: help


help:
	echo "make lint		- smilint"
	echo "make tree		- smidump -f tree"
	echo "make id		- smidump -f identifiers"


lint:
	SMIPATH=$(SMIPATH) smilint -m -s $(MIBFILE)

tree:
	SMIPATH=$(SMIPATH) smidump -f tree --tree-compact $(MIBFILE)

id:
	SMIPATH=$(SMIPATH) smidump -f identifiers $(MIBFILE)
