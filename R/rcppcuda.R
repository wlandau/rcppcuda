#' @title Class \code{MyClass}
#' @description A toy class for figuring out how to pass s4 objects from R to C++.
#' 
#' @exportClass MyClass
#' @aliases MyClass
#' @rdname MyClass
#' 
#' @slot x a numeric vector
#' @slot y an integer vector
setClass("MyClass", slots = list(x = "numeric", y = "integer"))

#' @title Function \code{hello}
#' @description Main function of the package. Passes a \code{MyClass}
#' object from R to C++, runs som CUDA code, changes, the object,
#' and prints the result
#' 
#' @export
#' @rdname hello
#' @aliases hello
hello = function() {
  r = new("MyClass", x = as.double(1:10), y = as.integer(1:10))
  print(r)
 # .Call('someCPPcode', r)
  someCPPcode(r)
  print("Object changed.")
  print(r)
}
