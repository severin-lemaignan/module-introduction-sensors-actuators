
Conversion from pptx to Beamer:

1- In LibreOffice, export as single page HTML document

2- Pandoc:

```
pandoc -s --latex-engine=lualatex -t beamer --template hri-pandoc-template.beamer -V theme:hri slides.html -o slides.tex
```
