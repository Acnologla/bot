open CommandRegister
open Discord
let register = (commands) => {
    name: ["help"],
    run: (message, _) =>{
        let text = List.map((command) => "`" ++ List.hd(command.name) ++ "`", commands) 
        |> String.concat(", ")
        let embed = Embed.create()
        |> Embed.title("help")
        |> Embed.description(text)
        Message.reply(message, Discord.Embed({embed: embed}))
    }
}