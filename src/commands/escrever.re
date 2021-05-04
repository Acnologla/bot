open CommandRegister
let register = () => {
    name: ["escrever"],
    run: (message, client) => {
        Args.parse(message.content)
        |> Js.Array.joinWith(" ")
        |> Js.String.split("")
        |> Array.mapi((i, char) =>i mod 2 == 0 ? String.uppercase(char) : String.lowercase(char))
        |> Array.to_list
        |> String.concat("")
        |> Discord.toStr
        |> Discord.Message.reply(message)
    }
}