obj-m += main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	@mkdir -p build
	@mv -f *.ko *.mod.c *.o *.mod.o *.symvers *.order .tmp_versions build/

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	@rm -rf build
