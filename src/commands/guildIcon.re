open CommandRegister
open Discord
let register = () => {
    name: ["guildicon"],
    run: (message, _) =>{
        Embed.create()
        |> Embed.title(message.guild.name)
        |> Embed.image({url:Guild.iconURL(message.guild)})
        |> toEmbed
        |> Message.reply(message)
    }
}