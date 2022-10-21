using System.Runtime.Serialization;

namespace Almostengr.AlmostengrWebsite
{
    [Serializable]
    internal class NwsObservationYesterDayCountZeroException : Exception
    {
        public NwsObservationYesterDayCountZeroException()
        {
        }

        public NwsObservationYesterDayCountZeroException(string message) : base(message)
        {
        }

        public NwsObservationYesterDayCountZeroException(string message, Exception? innerException) : base(message, innerException)
        {
        }

        protected NwsObservationYesterDayCountZeroException(SerializationInfo info, StreamingContext context) : base(info, context)
        {
        }
    }
}