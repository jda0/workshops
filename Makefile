all: serve

serve:
	bundler exec jekyll serve --baseurl ''

build:
	bundler exec jekyll build
