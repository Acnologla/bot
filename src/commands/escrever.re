open CommandRegister
let register = () => {
  name: ["escrever"],
  description: "Escreva algo",
  run: (message, _) => {
    Args.parse(message.content)
    |> Js.Array.joinWith(" ")
    |> String.mapi(i => i mod 2 == 0 ? Char.uppercase_ascii : Char.uppercase_ascii)
    |> Discord.toStr
    |> Discord.Message.reply(message)
  }
}