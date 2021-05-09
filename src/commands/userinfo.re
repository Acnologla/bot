open CommandRegister
open Discord
let getSharedGuilds = (client: Client.t, id) => Collection.filter(client.guilds.cache, guild => Collection.get(guild.members.cache, id) |>  Belt.Option.isSome)  
let register = () => {
  name: ["userinfo"],
  description: "Veja informaçoes sobre alguem",
  run: (message, client) => {
    let user = Utils.getUser(message)
    let guilds = getSharedGuilds(client, user.id)
    -> Collection.map(guild => guild.name) 
    |> Js.Array.joinWith(" ")
    let days = ( Js.Date.now() -. user.createdTimestamp) /. 1000.0 /. 60.0 /. 60.0 /. 24.0
    Embed.(
        create()
        |> title(user.tag)
        |> thumbnail({url: User.avatarURL(user)})
        |> color(65535)
        |> description("Conta criada a **" ++ (Js.Math.floor(days) |> string_of_int) ++ "** Dias")
        |> addField({
            name: "Servidores compartilhados",
            inline: false,
            value: guilds
        })
        |> toEmbed
        |> Message.reply(message)
    )
  }
}
