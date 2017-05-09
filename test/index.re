let cache = FlatCache.load "myCache";

module Cache = FlatCache.Make({
    type t = Js.t {.
        toppings: array string
    };
});

Cache.setKey cache "pizza" [%bs.obj { toppings: [| "cheese", "bacon" |]}];
Js.log @@ Cache.getKey cache "pizza";

FlatCache.save cache;

FlatCache.clearCacheById "myCache";
FlatCache.clearAll ();