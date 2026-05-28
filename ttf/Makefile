retrofont := retrofont
destination := ~/.local/share/fonts

files = $(basename $(notdir $(wildcard $(1))))
f2t = $(addprefix $(1)_,$(addsuffix .ttf,$(call files,$(2))))
f2tp = $(addprefix $(1)_,$(addsuffix _P.ttf,$(call files,$(2))))

fonts := \
	$(call f2t,Atari,../a8/*.FNT) \
	$(call f2tp,Atari,../a8/*.FNT) \
	$(call f2t,Apple,../apple/*.bin) \
	$(call f2tp,Apple,../apple/*.bin) \
	$(call f2t,BBC,../bbc/fonts/*.vdu) \
	$(call f2tp,BBC,../bbc/fonts/*.vdu) \
	$(call f2t,BBC,../bbc/romfonts/*.bin) \
	$(call f2tp,BBC,../bbc/romfonts/*.bin) \
	$(call f2t,C64,../c64/*.64C) \
	$(call f2tp,C64,../c64/*.64C) \
	$(call f2t,CPC,../cpc/*.raw) \
	$(call f2tp,CPC,../cpc/*.raw) \
	$(call f2t,MSX,../msx/*.raw) \
	$(call f2tp,MSX,../msx/*.raw) \
	$(call f2t,Oric,../oric/*.bin) \
	$(call f2tp,Oric,../oric/*.bin) \
	$(call f2t,PC,../pc/*.bin ../pc/*.raw) \
	$(call f2tp,PC,../pc/*.bin ../pc/*.raw) \
	$(call f2t,ZX,../zx/*.ch8 ../zx/fonts/*.ch8 ../zx/zx-origins/*.ch8) \
	$(call f2tp,ZX,../zx/*.ch8 ../zx/fonts/*.ch8 ../zx/zx-origins/*.ch8)

convert = $(retrofont) rom2ttf -s $(1) $(1)_$(2) $<
convert_p = $(retrofont) rom2ttf -s $(1) -p $(1)_$(2)_P $<


Atari_%.ttf: ../a8/%.FNT
	$(call convert,Atari,$*)

Atari_%_P.ttf: ../a8/%.FNT
	$(call convert_p,Atari,$*)

Apple_%.ttf: ../apple/%.bin
	$(call convert,Apple,$*)

Apple_%_P.ttf: ../apple/%.bin
	$(call convert_p,Apple,$*)

BBC_%.raw: ../bbc/fonts/%.vdu
	python vdu2raw.py < $< > $@

BBC_%.ttf: BBC_%.raw
	$(call convert,BBC,$*)

BBC_%_P.ttf: BBC_%.raw
	$(call convert_p,BBC,$*)

BBC_%.ttf: ../bbc/romfonts/%.bin
	$(call convert,BBC,$*)

BBC_%_P.ttf: ../bbc/romfonts/%.bin
	$(call convert_p,BBC,$*)

C64_%.raw: ../c64/%.64C
	dd if=$< of=$@ bs=1 skip=2

C64_%.ttf: C64_%.raw
	$(call convert,C64,$*)

C64_%_P.ttf: C64_%.raw
	$(call convert_p,C64,$*)

CPC_%.ttf: ../cpc/%.raw
	$(call convert,CPC,$*)

CPC_%_P.ttf: ../cpc/%.raw
	$(call convert_p,CPC,$*)

MSX_%.ttf: ../msx/%.raw
	$(call convert,MSX,$*)

MSX_%_P.ttf: ../msx/%.raw
	$(call convert_p,MSX,$*)

Oric_%.ttf: ../oric/%.bin
	$(call convert,Oric,$*)

Oric_%_P.ttf: ../oric/%.bin
	$(call convert_p,Oric,$*)

PC_%.ttf: ../pc/%.bin
	$(call convert,PC,$*)

PC_%_P.ttf: ../pc/%.bin
	$(call convert_p,PC,$*)

PC_%.ttf: ../pc/%.raw
	$(call convert,PC,$*)

PC_%_P.ttf: ../pc/%.raw
	$(call convert_p,PC,$*)

ZX_%.ttf: ../zx/%.ch8
	$(call convert,ZX,$*)

ZX_%_P.ttf: ../zx/%.ch8
	$(call convert_p,ZX,$*)

ZX_%.ttf: ../zx/fonts/%.ch8
	$(call convert,ZX,$*)

ZX_%_P.ttf: ../zx/fonts/%.ch8
	$(call convert_p,ZX,$*)

ZX_%.ttf: ../zx/zx-origins/%.ch8
	$(call convert,ZX,$*)

ZX_%_P.ttf: ../zx/zx-origins/%.ch8
	$(call convert_p,ZX,$*)


installed_fonts := $(addprefix $(destination)/,$(fonts))


all: $(fonts)

$(destination):
	mkdir -p $@

$(destination)/%: % | $(destination)
	cp $< $@

install: $(installed_fonts)
	fc-cache $(destination)

clean:
	rm -f $(fonts)
