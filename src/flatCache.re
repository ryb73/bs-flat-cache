type t;

external load : string => t = "" [@@bs.module "flat-cache"];
external clearAll : unit => unit = "" [@@bs.module "flat-cache"];
external clearCacheById : string => unit = "" [@@bs.module "flat-cache"];

external removeKey : string => t => unit = "" [@@bs.send];
external save : t => unit = "" [@@bs.send];

module type CacheItem = { type t; };
module Make(CacheItem : CacheItem) => {
    external setKey : t => string => CacheItem.t => unit = "" [@@bs.send];
    external getKey : t => string => CacheItem.t = "" [@@bs.send];
};