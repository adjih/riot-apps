
# Sample sensor test

We are using a [TinkerKit LDR sensor](https://store.arduino.cc/product/T000090)
contected to a [SAMR21 Xplained Pro](https://github.com/RIOT-OS/RIOT/wiki/Board%3A-SAMR21-xpro).

The light sensor is designed for Arduino devices, and includes two lines for powering it, and was initially designed to be powered in 5v
[Saved info](http://web.archive.org/web/20140724114216/http://www.tinkerkit.com/ldr/)

## Connecting the light sensor:

See the [Atmel documentation for the SAMR21 XPRO](http://www.atmel.com/images/atmel-42243-samr21-xplained-pro_user-guide.pdf) for reference for connecting the various devices.

### Powering the sensor

In the Xplained Pro Power Header, "the power header can also be used as
supply for external peripherals or extension boards." (section 3.4.2, p10).
To do so, (table 3-5), the pin #2 provices Ground, while the pin #4 (VCC_P3V3) provides "Regulated 3.3V (output, used as main power supply for the kit)"

### Connecting the sensor

The [Watr.li](http://watr.li) project includes a presentation of an example of how to use an [ADC for an humidity sensor](http://watr.li/Sensing-moisture.html) on a SAMR21 board.

On the software side, several generations of branches/pull requests have been proposed in the ADC API for the SAMR21, and the main RIOT repository, as of 2016/02/19, does not yet integrate ADC for the SAMR21:
in [watr.li RIOT fork](https://github.com/RIOT-OS/RIOT/compare/master...watr-li:master)
with also code
by [Rane Balslev](https://github.com/RIOT-OS/RIOT/pull/2063) and Peter Kietzmann;
then by [Mark Solters](https://github.com/RIOT-OS/RIOT/pull/4162) integrating/configuring a lots of ADC features of the SAMD21;
as of 2016/02/19 there is a rework on the ADC driver interface for all boards by [Hauke](https://github.com/RIOT-OS/RIOT/pull/4430), and Hauke had also a (older) [branch with basic ADC support](https://github.com/RIOT-OS/RIOT/compare/master...haukepetersen:add_samd21_adc) for SAMR21/SAMD21.

On the hardware side, there are several issues, including the fact that some ADC pin are used for other functions when using the EDBG USB interface (i.e. flashing via USB connector) and prevent to the use of external reference tension.

### Reading an analog sensor - with branch RIOT:add_samd21_adc

Using the older branch from Hauke:
```git clone https://github.com/haukepetersen/RIOT.git RIOT-hauke -b add_samd21_adc```

In this branch, there is only one ADC available: it corresponds to
the pin *PA08* (of the header EXT3)

The current RIOT [API for ADC](http://riot-os.org/api/group__drivers__periph__adc.html) of 2016/02/19 will change (in watr.li, [adc_test from watr.li](https://github.com/watr-li/nodes/blob/master/adc_test/main.c) is using this API)

It consist in:
* initialization: `adc_init(<adc device index>, <adc resolution>)`
* reading data: `adc_sample(<adc device index>, <adc channel inde>)`

----



