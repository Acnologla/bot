open CommandRegister
open Discord
let register = () => {
  name: ["avatar"],
  description: "Veja o avatar de alguem",
  run: (message, _) => {
    let user = message.mentions.users.size > 0 ?  Collection.first(message.mentions.users) : message.author
    Embed.create()
    |> Embed.title(user.tag)
    |> Embed.image({url: User.avatarURL(user)})
    |> toEmbed
    |> Message.reply(message)
  }
}
