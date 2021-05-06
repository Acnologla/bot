open CommandRegister
open Discord
let register = () => {
  name: ["avatar"],
  description: "Veja o avatar de alguem",
  run: (message, _) => {
    let user =
      if (message.mentions.users.size > 0) {
        Collection.first(message.mentions.users)
      } else {
        message.author
      }
    Embed.create()
    |> Embed.title(user.tag)
    |> Embed.image({url: User.avatarURL(user)})
    |> toEmbed
    |> Message.reply(message)
  }
}
