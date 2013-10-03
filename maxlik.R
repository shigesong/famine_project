# Example on pages 45-46, "Methods of Statistical Model Estimation"

jll.watson <- function(theta, x) {
  sum(log(1 + theta) - log(theta) - 2*log(1 + x / theta))
}

watson.fit <- function(x, ...) {
    optim(0.5,
            jll.watson,
            x = x,
            method = "Brent",
            lower = 0, upper = 1,
            control = list(fnscale= -1), ...)
}

large.sample <- rep(1:10, 10)/20

large.sample.fit <- watson.fit(large.sample)

large.sample.fit

# Using maxLik

library(maxLik)

mle <- maxLik(logLik = jll.watson, start=.1, x=large.sample)

summary(mle)

