PS5_PAYLOAD_SDK ?= $(CURDIR)/ps5-payload-sdk
include $(PS5_PAYLOAD_SDK)/toolchain.mk

PAYLOAD := ppr_sniffer.elf
OBJS := ppr_sniffer.o

all: $(PAYLOAD)

$(PAYLOAD): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(PAYLOAD)

-include $(PS5_PAYLOAD_SDK)/rules.mk
