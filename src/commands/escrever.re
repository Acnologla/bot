open CommandRegister
let register = () => {
    name: ["escrever"],
    run: (message, _) => {
        Args.parse(message.content)
        |> Js.Array.joinWith(" ")
        |> String.mapi(i => i mod 2 == 0 ? Char.uppercase : Char.lowercase)
        |> Discord.toStr
        |> Discord.Message.reply(message)
    }
}