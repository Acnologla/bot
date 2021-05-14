open CommandRegister
open Canvas
open Discord
open Js.Promise
open Context

let monkey_url = "https://raw.githubusercontent.com/Acnologla/asura/master/resources/monkey.png";

let register = () => {
  name: ["monkey"],
  description: "macaco",
  run: (message, _) => {
    let url = User.displayAvatarURL(message.author, {format: "png", size: 512});
    all2((loadImage(monkey_url),loadImage(url))) 
    |> then_(((img, avatar)) => {
          let canvas = createCanvas(491, 406)
          let ctx = getContext(canvas, "2d")
          drawImage(ctx,avatar, 0,0, 491, 406)
          drawImage(ctx,img, 0,0, 491, 406)
          Canvas.toBuffer(canvas)
          -> messageAttachment("monkey.png")
          |> toBuffer
          |> Message.reply(message);
          resolve(None)
    })
    |> ignore
  },
}