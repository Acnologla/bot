open CommandRegister
open Discord
let register = () => {
  name: ["guildinfo"],
  description: "guildInfo",
  run: (message, _) =>
   Embed.(
       create()
       |> title(message.guild.name)
       |> description("Membros: " ++ string_of_int(message.guild.members.cache.size) ++ "\nCanais: " ++ string_of_int(message.guild.channels.cache.size))
       |> color(65535)
       |> addField({
           inline: false,
           name: "Dono",
           value: message.guild.owner.user.tag
       })
       |> addField({
           inline: false,
           name: "Cargos",
           value: Collection.map(message.guild.roles.cache, role => role.name) |> Js.Array.joinWith(", ")
       })
       |> addField({
           inline: false,
           name: "Canais",
           value: Collection.map(message.guild.channels.cache, channel => channel.name ++ Channel.getType(channel)) |> Js.Array.joinWith(", ")
       })
       |> toEmbed
       |> Message.reply(message)
   )
}
