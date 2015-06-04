setClass("MyClass", slots = list(x = "numeric", y = "integer"))

hello = function() {
  r = new("MyClass", x = as.double(1:10), y = as.integer(1:10))
  print(r)
  .Call('someCPPcode', r)
  print("Object changed.")
  print(r)
}
