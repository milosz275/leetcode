SUBDIRS := $(filter-out docs/, $(wildcard */))

all: $(SUBDIRS)
	@echo "Successfully build all subdirectories."

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

.PHONY: all $(SUBDIRS) clean
