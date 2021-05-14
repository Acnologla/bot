module Image = {
    type t = {
        width: int,
        height: int
    };
}

module Canvas = {
    type t = {
        _type: string
    };
    [@bs.send] external toBuffer : (t) => Js_typed_array.array_buffer;
}
module Context = {
    type t = {
        font: string
    };
    [@bs.send] external getContext : Canvas.t => string => t;
    [@bs.send] external drawImage : (t, Image.t, int, int, int, int) => unit;
}

[@bs.module "canvas"] external createCanvas: (int, int) => Canvas.t;
[@bs.module "canvas"] external loadImage: string => Js.Promise.t(Image.t);
