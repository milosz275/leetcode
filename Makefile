SUBDIRS := $(shell find . -mindepth 2 -type f -name Makefile | sed 's|/[^/]*$$||' | sort -u | grep -v './docs' | grep -v './.notes')

all: $(SUBDIRS)
	@echo "Successfully build all subdirectories."

$(SUBDIRS):
	$(MAKE) -C $@

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

.PHONY: all $(SUBDIRS) clean
