open CommandRegister
open Discord
let register = (commands) => {
    name: ["help"],
    run: (message, client) =>{
        let text = List.map((command) => "`" ++ List.nth(command.name,0) ++ "`",commands) 
        |> String.concat(", ")
        let embed = Embed.create()
        |> Embed.title("help")
        |> Embed.description(text)
        Message.reply(message, Discord.Embed({embed: embed}))
    }
}