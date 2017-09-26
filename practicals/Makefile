
LATEX=lualatex

TEXTARGETS=$(wildcard ./[1-9]*/[1-9]*.tex)

TARGET=$(TEXTARGETS:.tex=.pdf)

DOT=$(wildcard figs/*.dot)
SVG=$(wildcard part[1-9]*/figs/*.svg)

MODE ?= batchmode

all: paper

$(SVG:.svg=.pdf): %.pdf: %.svg
	inkscape --export-pdf $(@) $(<)

%.aux: paper

%.svg: %.dot
	twopi -Tsvg -o$(@) $(<)

bib: $(TARGET:.tex=.aux)
	BSTINPUTS=:./style bibtex $(TARGET:.tex=.aux)

%.pdf: %.tex
	cd `dirname $<`; \
	TEXINPUTS=:../style $(LATEX) --interaction=$(MODE) -shell-escape `basename $<`; if [ $$? -gt 0 ]; then echo "Error while compiling $<"; touch `basename $<`; fi; \
	cd -

paper: $(SVG:.svg=.pdf) $(DOT:.dot=.pdf) $(TARGET)

touch:
	touch $(TEXTARGETS)

force: touch paper

%.nup: %.pdf
	pdfnup --nup 2x5 --no-landscape $<

nup: $(TARGET:.pdf=.nup)

clean:
	rm -f */*.vrb */*.spl */*.idx */*.aux */*.log */*.snm */*.out */*.toc */*.nav */*intermediate */*~ */*.glo */*.ist */*.bbl */*.blg $(SVG:.svg=.pdf) $(DOT:.dot=.svg) $(DOT:.dot=.pdf)
	rm -rf */_minted*

distclean: clean
	rm -f $(TARGET:.tex=.pdf)
