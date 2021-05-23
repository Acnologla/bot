open Schema
type userSchema = {
    aboutMe: string
}

let users: Schema.t(userSchema) = newSchema("users")