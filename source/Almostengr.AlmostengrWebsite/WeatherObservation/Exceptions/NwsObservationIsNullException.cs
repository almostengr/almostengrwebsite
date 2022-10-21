using System.Runtime.Serialization;

namespace Almostengr.AlmostengrWebsite
{
    [Serializable]
    internal class NwsObservationIsNullException : Exception
    {
        public NwsObservationIsNullException()
        {
        }

        public NwsObservationIsNullException(string message) : base(message)
        {
        }

        public NwsObservationIsNullException(string message, Exception? innerException) : base(message, innerException)
        {
        }

        protected NwsObservationIsNullException(SerializationInfo info, StreamingContext context) : base(info, context)
        {
        }
    }
}