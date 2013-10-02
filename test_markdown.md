How to create a regression table in R Markdown
========================================================




Zelig is a powerful *R* package (<a href="http://dx.doi.org/10.1198/106186008X384898">Imai et al. 2008</a> ). It provides an unified interface to a large number of existing *R* packages for statistical estimation. In addition, it implements the powerful statistical simulation methodology proposed by <a href="http://dx.doi.org/10.2307/2669316">King et al. (2000)</a> .

The package "texreg" has a function called ``htmlreg()'' that can be used to produce regression tables in R Markdown. Here is a simple example showing how "texreg" and "Zelig" can work together:


```r
library(Zelig)

data(turnout)

z.out1 <- zelig(vote ~ age, model = "logit", data = turnout)
z.out2 <- zelig(vote ~ age + race, model = "logit", data = turnout)
z.out3 <- zelig(vote ~ age + race + educate, model = "logit", data = turnout)
```

The "texreg" package is very powerful and flexible. I also like the "stargazer" package but, unfortunately, it does not produce html code so it cannot be used here. 


```r
library(texreg)

htmlreg(list(z.out1, z.out2, z.out3), doctype = F, html.tag = F, inline.css = T, 
    head.tag = F, body.tag = F, center = F, single.row = T, caption = "")
```


<table cellspacing="0" style="border: none;">
  <tr>
    <th style="text-align: left; border-top: 2px solid black; border-bottom: 1px solid black; padding-right: 12px;"></th>
    <th style="text-align: left; border-top: 2px solid black; border-bottom: 1px solid black; padding-right: 12px;"><b>Model 1</b></th>
    <th style="text-align: left; border-top: 2px solid black; border-bottom: 1px solid black; padding-right: 12px;"><b>Model 2</b></th>
    <th style="text-align: left; border-top: 2px solid black; border-bottom: 1px solid black; padding-right: 12px;"><b>Model 3</b></th>
  </tr>
  <tr>
    <td style="padding-right: 12px; border: none;">(Intercept)</td>
    <td style="padding-right: 12px; border: none;">0.55 (0.14)<sup style="vertical-align: 4px;">***</sup></td>
    <td style="padding-right: 12px; border: none;">0.04 (0.18)</td>
    <td style="padding-right: 12px; border: none;">-3.05 (0.33)<sup style="vertical-align: 4px;">***</sup></td>
  </tr>
  <tr>
    <td style="padding-right: 12px; border: none;">age</td>
    <td style="padding-right: 12px; border: none;">0.01 (0.00)<sup style="vertical-align: 4px;">***</sup></td>
    <td style="padding-right: 12px; border: none;">0.01 (0.00)<sup style="vertical-align: 4px;">***</sup></td>
    <td style="padding-right: 12px; border: none;">0.03 (0.00)<sup style="vertical-align: 4px;">***</sup></td>
  </tr>
  <tr>
    <td style="padding-right: 12px; border: none;">racewhite</td>
    <td style="padding-right: 12px; border: none;"></td>
    <td style="padding-right: 12px; border: none;">0.65 (0.13)<sup style="vertical-align: 4px;">***</sup></td>
    <td style="padding-right: 12px; border: none;">0.38 (0.14)<sup style="vertical-align: 4px;">**</sup></td>
  </tr>
  <tr>
    <td style="padding-right: 12px; border: none;">educate</td>
    <td style="padding-right: 12px; border: none;"></td>
    <td style="padding-right: 12px; border: none;"></td>
    <td style="padding-right: 12px; border: none;">0.22 (0.02)<sup style="vertical-align: 4px;">***</sup></td>
  </tr>
  <tr>
    <td style="border-top: 1px solid black;">AIC</td>
    <td style="border-top: 1px solid black;">2254.91</td>
    <td style="border-top: 1px solid black;">2234.82</td>
    <td style="border-top: 1px solid black;">2080.03</td>
  </tr>
  <tr>
    <td style="padding-right: 12px; border: none;">BIC</td>
    <td style="padding-right: 12px; border: none;">2266.12</td>
    <td style="padding-right: 12px; border: none;">2251.62</td>
    <td style="padding-right: 12px; border: none;">2102.43</td>
  </tr>
  <tr>
    <td style="padding-right: 12px; border: none;">Log Likelihood</td>
    <td style="padding-right: 12px; border: none;">-1125.46</td>
    <td style="padding-right: 12px; border: none;">-1114.41</td>
    <td style="padding-right: 12px; border: none;">-1036.01</td>
  </tr>
  <tr>
    <td style="padding-right: 12px; border: none;">Deviance</td>
    <td style="padding-right: 12px; border: none;">2250.91</td>
    <td style="padding-right: 12px; border: none;">2228.82</td>
    <td style="padding-right: 12px; border: none;">2072.03</td>
  </tr>
  <tr>
    <td style="border-bottom: 2px solid black;">Num. obs.</td>
    <td style="border-bottom: 2px solid black;">2000</td>
    <td style="border-bottom: 2px solid black;">2000</td>
    <td style="border-bottom: 2px solid black;">2000</td>
  </tr>
  <tr>
    <td style="padding-right: 12px; border: none;" colspan="4"><span style="font-size:0.8em"><sup style="vertical-align: 4px;">***</sup>p &lt; 0.001, <sup style="vertical-align: 4px;">**</sup>p &lt; 0.01, <sup style="vertical-align: 4px;">*</sup>p &lt; 0.05</span></td>
  </tr>
</table>


Here are some figures:


```r
x.out2 <- setx(z.out2, age = 36, race = "white")
x.out2
s.out2 <- sim(z.out2, x = x.out2)
```



```r
plot(s.out2)
```

![plot of chunk unnamed-chunk-5](figure/unnamed-chunk-5.png) 


Now what do these figures show?

Of course, you also need *R*, *Rstudio*, *knitr*, and *knitcitations*, which are all *free*. 

REFERENCES


- Kosuke Imai, Gary King, Olivia Lau,   (2008) Toward A Common Framework For Statistical Analysis And Development.  *Journal of Computational And Graphical Statistics*  **17**  892-913  [10.1198/106186008X384898](http://dx.doi.org/10.1198/106186008X384898)
- Gary King, Michael Tomz, Jason Wittenberg,   (2000) Making The Most of Statistical Analyses: Improving Interpretation And Presentation.  *American Journal of Political Science*  **44**  347-NA  [10.2307/2669316](http://dx.doi.org/10.2307/2669316)


